function getStyle(element) {
  if (!element.computedLayoutStyle) {
    element.computedLayoutStyle = {};
  }

  let elementStyle = {};
  for (let prop in element.computedStyle) {
    elementStyle[prop] = element.computedStyle[prop].value;

    if (elementStyle[prop].toString().match(/px$/)) {
      elementStyle[prop] = parseInt(elementStyle[prop]);
    }
    if (elementStyle[prop].toString().match(/^[0-9\.]+$/)) {
      elementStyle[prop] = parseInt(elementStyle[prop]);
    }
  }

  element.computedLayoutStyle = elementStyle
  return element.computedLayoutStyle;
}

function layout(element) {
  if (!element.computedStyle) {
    return;
  }

  let computedLayoutStyle = getStyle(element);
  // 暂时只处理 flex 排版
  if (computedLayoutStyle.display === 'flex') {
    // 过滤掉文本节点
    let flexItems = element.children.filter(child => child.type === 'element');

    flexItems.sort((a, b) => {
      return (a.order || 0) - (b.order || 0);
    })

    for (let prop of ['width, height']) {
      if (computedLayoutStyle[prop] === 'auto' || computedLayoutStyle[prop] === '') {
        computedLayoutStyle[prop] = null;
      }
    }

    // 部分 flex 属性设置默认值
    if (!computedLayoutStyle.flexDirection || computedLayoutStyle.flexDirection === 'auto') {
      computedLayoutStyle.flexDirection = 'row';
    }
    if (!computedLayoutStyle.alignItems || computedLayoutStyle.alignItems === 'auto') {
      computedLayoutStyle.alignItems = 'stretch';
    }
    if (!computedLayoutStyle.justifyContent || computedLayoutStyle.justifyContent === 'auto') {
      computedLayoutStyle.justifyContent = 'flex-start';
    }
    if (!computedLayoutStyle.flexWrap || computedLayoutStyle.flexWrap === 'auto') {
      computedLayoutStyle.flexWrap = 'nowrap';
    }
    if (!computedLayoutStyle.alignContent || computedLayoutStyle.alignContent === 'auto') {
      computedLayoutStyle.alignContent = 'stretch';
    }

    // 根据主轴方向，设置相关变量的值
    let mainAxisSize, mainAxisStart, mainAxisEnd, mainAxisSign, mainAxisBase,
      crossAxisSize, crossAxisStart, crossAxisEnd, crossAxisSign, crossAxisBase;
    if (computedLayoutStyle.flexDirection === 'row') {
      mainAxisSize = 'width';
      mainAxisStart = 'left';
      mainAxisEnd = 'right';
      mainAxisSign = +1;
      mainAxisBase = 0;

      crossAxisSize = 'height';
      crossAxisStart = 'top';
      crossAxisEnd = 'bottom';
    }
    if (computedLayoutStyle.flexDirection === 'row-reverse') {
      mainAxisSize = 'width';
      mainAxisStart = 'right';
      mainAxisEnd = 'left';
      mainAxisSign = -1;
      mainAxisBase = computedLayoutStyle.width;

      crossAxisSize = 'height';
      crossAxisStart = 'top';
      crossAxisEnd = 'bottom';
    }
    if (computedLayoutStyle.flexDirection === 'column') {
      mainAxisSize = 'height';
      mainAxisStart = 'top';
      mainAxisEnd = 'bottom';
      mainAxisSign = +1;
      mainAxisBase = 0;

      crossAxisSize = 'width';
      crossAxisStart = 'left';
      crossAxisEnd = 'right';
    }
    if (computedLayoutStyle.flexDirection === 'column-reverse') {
      mainAxisSize = 'height';
      mainAxisStart = 'bottom';
      mainAxisEnd = 'top';
      mainAxisSign = -1;
      mainAxisBase = computedLayoutStyle.height;

      crossAxisSize = 'width';
      crossAxisStart = 'left';
      crossAxisEnd = 'right';
    }

    // wrap-reverse
    if (computedLayoutStyle.flexWrap === 'wrap-reverse') {
      // 交叉轴只受到 wrap-reverse 的影响
      var temp = crossAxisStart;
      crossAxisStart = crossAxisEnd;
      crossAxisEnd = temp;
      crossAxisSign = -1;
    } else {
      crossAxisBase = 0;
      crossAxisSign = +1;
    }

    // 元素进行
    let isAutoMainSize = false;
    if (!computedLayoutStyle[mainAxisSize]) { // auto size
      computedLayoutStyle[mainAxisSize] = 0;
      for (let flexItem of flexItems) {
        let itemStyle = getStyle(flexItem);
        if (itemStyle[mainAxisSize] !== null || itemStyle[mainAxisSize]) {
          computedLayoutStyle[mainAxisSize] += itemStyle[mainAxisSize];
        }
      }
      isAutoMainSize = true;
    }

    // 当前行和所有行
    let flexLine = [], flexLines = [flexLine];
    // 当前行上主轴和交叉轴的剩余空间
    let mainAxisSpace = computedLayoutStyle[mainAxisSize], crossAxisSpace = 0;
    for (let flexItem of flexItems) {
      let itemComputedLayoutStyle = getStyle(flexItem);
      if (itemComputedLayoutStyle[mainAxisSize] === null) {
        itemComputedLayoutStyle[mainAxisSize] = 0;
      }

      if (itemComputedLayoutStyle.flex) {
        flexLine.push(flexItem);
      } else if (itemComputedLayoutStyle.flexWrap === 'nowrap' && isAutoMainSize) {
        // 更新主轴、交叉轴的的剩余空间
        mainAxisSpace -= itemComputedLayoutStyle[mainAxisSize];
        if (itemComputedLayoutStyle[crossAxisSize] !== null && itemComputedLayoutStyle[crossAxisSize] !== (void 0)) {
          crossAxisSpace = Math.max(crossAxisSpace, itemComputedLayoutStyle[crossAxisSize]);
        }

        flexLine.push(flexItem);
      } else {
        // 子元素超出容器主轴宽度时
        if (itemComputedLayoutStyle[mainAxisSize] > computedLayoutStyle[mainAxisSize]) {
          itemComputedLayoutStyle[mainAxisSize] = computedLayoutStyle[mainAxisSize];
        }

        // 剩余空间不足以排进当前元素时
        if (mainAxisSpace < itemComputedLayoutStyle[mainAxisSize]) {
          // 换行
          flexLine = [flexItem];
          flexLines.push(flexLine);
          // 保存剩余空间信息
          flexLine.mainAxisSpace = mainAxisSpace;
          flexLine.crossAxisSpace = crossAxisSpace;
          // 重置剩余空间
          mainAxisSpace = computedLayoutStyle[mainAxisSize];
          crossAxisSpace = 0;
        } else {
          flexLine.push(flexItem)
        }

        // 更新主轴、交叉轴的的剩余空间
        mainAxisSpace -= itemComputedLayoutStyle[mainAxisSize];
        if (itemComputedLayoutStyle[crossAxisSize] !== null && itemComputedLayoutStyle[crossAxisSize] !== (void 0)) {
          crossAxisSpace = Math.max(crossAxisSpace, itemComputedLayoutStyle[crossAxisSize]);
        }
      }
    }

    flexLine.mainAxisSpace = mainAxisSpace;
    console.log(flexItems);
  } else {
    return;
  }
}


module.exports = layout;
