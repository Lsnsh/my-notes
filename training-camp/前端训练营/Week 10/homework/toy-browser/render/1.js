const images = require('images');

function render(viewport, element) {
  console.log('style: ', element.computedLayoutStyle);
  if (element.computedLayoutStyle) {
    let img = images(element.computedLayoutStyle.width, element.computedLayoutStyle.height);

    if (element.computedLayoutStyle['background-color']) {
      let color = element.computedLayoutStyle['background-color'] || 'rgb(0, 0, 0)';
      color.match(/rgb\((\d+),\s*(\d+),\s*(\d+)\)/);
      img.fill(Number(RegExp.$1), Number(RegExp.$2), Number(RegExp.$3));
      viewport.draw(img, element.computedLayoutStyle.left || 0, element.computedLayoutStyle.top || 0);
    }
  }
}

module.exports = render;
