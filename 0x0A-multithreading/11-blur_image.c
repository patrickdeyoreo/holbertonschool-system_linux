#include <pthread.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#include "multithreading.h"

/**
 * _thread_entry - thread entry point
 *
 * @arg: portion of image to blur
 *
 * Return: NULL
 */
static void *_thread_entry(void *arg)
{
	blur_portion((blur_portion_t *) arg);
	pthread_exit(NULL);
}

/**
 * _apportion_image - create image portions to blur
 *
 * @img_blur: blurred image
 * @img: image to apportion
 * @kernel: convolution kernel
 * @n: number of portions
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to a dynamically-allocated array of n portions.
 */
static blur_portion_t *_apportion_image(
	img_t *img_blur, img_t const *img, kernel_t const *kernel, int n)
{
	blur_portion_t *portions = malloc(sizeof(*portions) * n);
	size_t portion_x = 0;
	int i = 0;

	if (portions)
	{
		while (i < n)
		{
			portions[i].img = img;
			portions[i].img_blur = img_blur;
			portions[i].kernel = kernel;
			portions[i].x = portion_x;
			portions[i].y = 0;
			portions[i].w = img->w / n;
			portions[i].h = img->h;
			portion_x += img->w / n;
			i += 1;
		}
		portions[n - 1].w += img->w % n;
	}
	return (portions);
}

/**
 * blur_image - perform a Guassian blur using multiple threads
 *
 * @img_blur: destinaton image
 * @img: source image
 * @kernel: convolution kernel
 */
void blur_image(img_t *img_blur, img_t const *img, kernel_t const *kernel)
{
	int i = 0;
	int n = get_nprocs();
	pthread_t *tids = malloc(sizeof(*tids) * n);
	blur_portion_t *portions = _apportion_image(img_blur, img, kernel, n);

	if (tids && portions)
	{
		for (i = 0; i < n; i += 1)
			pthread_create(
				&tids[i], NULL, _thread_entry, &portions[i]);
		for (i = 0; i < n; i += 1)
			pthread_join(
				tids[i], NULL);
	}
	free(tids);
	free(portions);
}
