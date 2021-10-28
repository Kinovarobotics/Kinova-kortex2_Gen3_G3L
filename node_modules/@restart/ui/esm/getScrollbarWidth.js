/**
 * Get the width of the vertical window scrollbar if it's visible
 */
export default function getBodyScrollbarWidth() {
  return Math.abs(window.innerWidth - document.documentElement.clientWidth);
}