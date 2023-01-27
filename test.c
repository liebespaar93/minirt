// Copyright (C) 2022 Martin Weigel <mail@MartinWeigel.com>
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

// Version: 2022-05-16
// Usage:   gcc -std=c17 -Wall -Wextra example.c t_quaternion.c -o example.exe; ./example.exe

#include <stdlib.h>
#include "ft_quaternion.h"
#include <stdio.h>


#ifndef M_PI
    #define M_PI (3.14159265358979323846)
#endif

void Quaternion_fprint(t_quaternion* q)
{
    printf( "(%.3f, %.3f, %.3f, %.3f)",
        q->w, q->x, q->y, q->z);
}

int main(void)
{
	t_quaternion	q;
	t_quaternion	temp_q;
	t_quaternion	copy_q;
	t_quaternion	out_1;
	t_quaternion	out_2;
    t_quaternion rotate_x;
    t_quaternion rotate_y;
	double			angle;
	//double			temp;
	int				i, k, l;

    t_vec3 euler;

	euler = ft_vector_3(0.3, 0.1, 0.2);

	angle = 3600.0 / 180.0 / 11.0  * M_PI;
	
	double a;
	temp_q = ft_quaternion_euler_from_angles(euler);

	t_vec3 out;

	l=0;
	i = -11 / 2;
	while (i <= 11 / 2)
	{
		k = -11 / 2;
		while (k <= 11 / 2)
		{
            copy_q = temp_q;
            rotate_x = ft_quaternion_rotation_x(k * angle);
			rotate_y = ft_quaternion_rotation_y(i * angle);

			out_1 = ft_quaternion_multiply(copy_q, rotate_x);
			out_2 = ft_quaternion_multiply(out_1, rotate_y);

            out = ft_quaternion_euler_to_angles(out_2);
			printf("%+.2f %+.2f %+.2f  ", out.x, out.y, out.z );
			k++;
		}
		printf("\n");
		i++;
	}
    return EXIT_SUCCESS;
}
