"use strict";

exports.__esModule = true;
exports.default = getBodyScrollbarWidth;

/**
 * Get the width of the vertical window scrollbar if it's visible
 */
function getBodyScrollbarWidth() {
  return Math.abs(window.innerWidth - document.documentElement.clientWidth);
}