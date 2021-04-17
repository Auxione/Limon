#pragma once

#include <math.h>
#include "Raster.h"

namespace limon {
	namespace brush {

		/// <summary>
		/// Draws line from start to end using bresenham line algorithm. 
		/// </summary>
		/// <param name="raster">: the raster to draw line.</param>
		/// <param name="x1">: x axis value of the start position.</param>
		/// <param name="y1">: y axis value of the start position.</param>
		/// <param name="x2">: x axis value of the end position.</param>
		/// <param name="y2">: y axis value of the end position.</param>
		/// <param name="color">: color of the line.</param>
		const void DrawLine(IRaster& raster, const size_t x1, const size_t y1, const size_t x2, const size_t y2, const uint32_t color) {
			//bresenham line drawing algorithm: https://www.tutorialspoint.com/computer_graphics/line_generation_algorithm.htm
			//calculate the delta distance in each axis
			float dx = (float) (x2 - x1);
			float dy = (float) (y2 - y1);

			float dxAbs = fabsf(dx);
			float dyAbs = fabsf(dy);


			//select the biggest delta dist. as stepcount.
			float stepCount;
			if (dxAbs > dyAbs) {
				stepCount = dxAbs;
			} else {
				stepCount = dyAbs;
			}

			//calculate x,y increment value
			float Xincrement = dx / stepCount;
			float Yincrement = dy / stepCount;

			float x = (float) x1;
			float y = (float) y1;

			//set pixel in start position and increment seperately in each axis.
			raster.SetPixel(x1, y1, color);
			for (int v = 0; v < stepCount; v++) {
				x = x + Xincrement;
				y = y + Yincrement;
				raster.SetPixel((size_t) round(x), (size_t) round(y), color);
			}
		}

		/// <summary>
		/// Draws rectangle in x,y coordinates.
		/// The dimensions of the rectangle is determined by width and height params.
		/// The inside of the rectangle discarded.
		/// </summary>
		/// <param name="raster">: the raster to draw rectangle.</param>
		/// <param name="x">: x axis value of the top left corner.</param>
		/// <param name="y">: y axis value of the top left corner.</param>
		/// <param name="width">: the width of the rectangle.</param>
		/// <param name="height">: the height of the rectangle.</param>
		/// <param name="color">: the color of the rectangle.</param>
		const void DrawRect(IRaster& raster, const size_t x, const size_t y, const size_t width, const size_t height, const uint32_t color) {
			for (size_t dx = 0; dx < width; dx++) {
				for (size_t dy = 0; dy < height; dy++) {
					//discard inside of the rectangle
					if (dy >= 1 && dy < (height - 1) &&
						dx >= 1 && dx < (width - 1)) {
						continue;
					}

					raster.SetPixel(x + dx, y + dy, color);
				}
			}
		}

		/// <summary>
		/// Fills rectangular area in x,y coordinates.
		/// The dimensions of the area is determined by width and height params.
		/// </summary>
		/// <param name="raster">: the raster to fill area.</param>
		/// <param name="x">: x axis value of the top left corner.</param>
		/// <param name="y">: y axis value of the top left corner.</param>
		/// <param name="width">: the width of the rectangle.</param>
		/// <param name="height">: the height of the rectangle.</param>
		/// <param name="color">: the color of the rectangle.</param>
		const void FillRect(IRaster& raster, const size_t x, const size_t y, const size_t width, const size_t height, const uint32_t color) {
			for (size_t dx = 0; dx < width; dx++) {
				for (size_t dy = 0; dy < height; dy++) {
					raster.SetPixel(x + dx, y + dy, color);
				}
			}
		}

		/// <summary>
		/// Fills the entire raster with given color.
		/// </summary>
		/// <param name="raster">: the raster to fill</param>
		/// <param name="color">: the color.</param>
		const void Fill(IRaster& raster, const uint32_t color) {
			for (size_t dx = 0; dx < raster.GetWidth(); dx++) {
				for (size_t dy = 0; dy < raster.GetHeight(); dy++) {
					raster.SetPixel(dx, dy, color);
				}
			}
		}

		/// <summary>
		/// Flood fills the area given in x,y coordinates.
		/// This function recursively replaces each pixel color if values are same.
		/// </summary>
		/// <param name="raster">: the raster to fill</param>
		/// <param name="x">: x axis value of the start position.</param>
		/// <param name="y">: y axis value of the start position.</param>
		/// <param name="oldColor">: the color value to check pixel.</param>
		/// <param name="newColor">: the new color value to replace.</param>
		const void FloodFill(IRaster& raster, const size_t x, const size_t y, const uint32_t oldColor, const uint32_t newColor) {
			if (raster.GetPixel(x, y) == oldColor) {
				raster.SetPixel(x, y, newColor);

				FloodFill(raster, x, y - 1, oldColor, newColor);
				FloodFill(raster, x, y + 1, oldColor, newColor);
				FloodFill(raster, x - 1, y, oldColor, newColor);
				FloodFill(raster, x + 1, y, oldColor, newColor);
			}
		}
	}
}