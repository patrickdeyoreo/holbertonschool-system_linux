#include "multithreading.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * _blur_pixel - blur a pixel using a Gaussian blur
 *
 * @portion: pointer to the image portion to blur
 * @row: pixel row
 * @col: pixel column
 */
static void _blur_pixel(blur_portion_t const *portion, size_t row, size_t col)
{
	kernel_t const *kernel = portion->kernel;
	size_t blur_row = row;
	size_t blur_col = col;
	size_t kernel_row = 0;
	size_t kernel_col = 0;
	size_t kernel_row_start = row > kernel->size / 2 ? 0 : kernel->size / 2 - row;
	size_t kernel_col_start = col > kernel->size / 2 ? 0 : kernel->size / 2 - col;
	size_t row_start = row > kernel->size / 2 ? row - kernel->size / 2 : 0;
	size_t col_start = col > kernel->size / 2 ? col - kernel->size / 2 : 0;
	size_t row_end = MIN(row + (kernel->size - 1) / 2 + 1, portion->img->h);
	size_t col_end = MIN(col + (kernel->size - 1) / 2 + 1, portion->img->w);
	float r = 0;
	float g = 0;
	float b = 0;
	float k = 0;

	row = row_start;
	kernel_row = kernel_row_start;
	while (row < row_end)
	{
		col = col_start;
		kernel_col = kernel_col_start;
		while (col < col_end)
		{
			r += kernel->matrix[kernel_row][kernel_col] *
				portion->img->pixels[row * portion->img->w + col].r;
			g += kernel->matrix[kernel_row][kernel_col] *
				portion->img->pixels[row * portion->img->w + col].g;
			b += kernel->matrix[kernel_row][kernel_col] *
				portion->img->pixels[row * portion->img->w + col].b;
			k += kernel->matrix[kernel_row][kernel_col];
			col += 1;
			kernel_col += 1;
		}
		row += 1;
		kernel_row += 1;
	}
	portion->img_blur->pixels[blur_row * portion->img->w + blur_col].r = r / k;
	portion->img_blur->pixels[blur_row * portion->img->w + blur_col].g = g / k;
	portion->img_blur->pixels[blur_row * portion->img->w + blur_col].b = b / k;
}

/**
 * blur_portion - blur a portion of an image using a Gaussian blur
 *
 * @portion: pointer to the image portion to blur
 */
void blur_portion(blur_portion_t const *portion)
{
	size_t row = 0;
	size_t col = 0;

	for (row = portion->y; row < portion->y + portion->h; row += 1)
	{
		for (col = portion->x; col < portion->x + portion->w; col += 1)
			_blur_pixel(portion, row, col);
	}
}
