<p align="center">
	<img alt="FDF BADGE" src="https://github.com/tesla33io/FdF/blob/main/badge.png?raw=true" width="200">
</p>

This project is about creating a simple wireframe model of a landscape.

<details>
  <summary>Bresenham's Line Algorithm 🧙‍♂️</summary>

### Bresenham's Line Algorithm

Imagine you have a grid of dots (like a pixelated screen) and you want to draw the straightest possible line between two points. Bresenham's line algorithm helps you do this efficiently, without fancy math or floating-point calculations. Here's a breakdown:

**Starting Point:**

1. You know the starting point (x1, y1) and the ending point (x2, y2).
2. Figure out the direction: Is x2 to the right or left of x1? Up or down from y1? This affects the calculations later.

**Step by Step:**

1. You only move horizontally (one dot to the right or left) or diagonally (one dot right or left and one dot up or down).
2. To decide which pixel to choose next, Bresenham uses a clever trick:
    - He calculates an "error term" that tracks how far the current path deviates from the perfect straight line.
    - By comparing the error term to certain thresholds, he decides whether to just move horizontally or diagonally, keeping the line as close as possible to the ideal path.
3. He repeats step 2, moving pixel by pixel, updating the error term and choosing the next point, until he reaches the end point.

**Key details:**

- Since everything is based on integer calculations (adding and subtracting 1s), it's fast and works well on computers.
- It handles all slopes (even steep diagonals) by adjusting the error term calculations based on the direction.
- It doesn't involve tricky floating-point numbers or complex math, making it easy to understand and implement.

**Resources:**

- Here's a visual explanation of the algorithm: [https://digitalbunker.dev/bresenhams-line-algorithm/](https://digitalbunker.dev/bresenhams-line-algorithm/)
- For a deeper dive, you can find C code implementations and more detailed explanations online.

**Additional Notes:**

- Bresenham's algorithm doesn't automatically handle antialiasing, so lines might appear jagged, especially at angles.
- There are variations of the algorithm that can handle thicker lines or different line styles.

</details>
