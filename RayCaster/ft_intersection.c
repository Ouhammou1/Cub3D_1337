/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:58:25 by bouhammo          #+#    #+#             */
/*   Updated: 2024/12/12 21:18:45 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../cub.h"

void drawing_line(t_start *var , int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

// if ( x0 <= INT_MIN || y0 <= INT_MIN || x1 <= INT_MIN || y1 <= INT_MIN)
// {
// 	printf("++++++++++++++++++++++++++++++++++++++++           \n");
// 	return ;
// }
    // printf(" x0 [%d]\n  y0 [%d]\n  x1 [%d]\n  y1 [%d] \n\n", x0, y0, x1, y1);

    while (true) {
        if (x0 < 0 || y0 < 0 || x0 >= var->move->width_x || y0 >= var->move->height_y)
            return;

        ft_put_pixel(var, x0, y0);

        if (x0 == x1 && y0 == y1)
            break;
        
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int check_uniq_rays(t_start *var, double x, double y)
{
    int  map_x ;
    int  map_y ;
    if (!var || !var->move || !var->map)
        return -1;
    if (x + 1 < 0 || x + 1 >= var->move->width_x || y + 1 < 0 || y + 1 >= var->move->height_y)
        return -1;
    x++;
    map_x = (int)(x / TILE_SIZE);
    map_y = (int)(y / TILE_SIZE);
    if (var->map[map_y][map_x] == '1')
        return 0;
    y++;
    map_x = (int)(x / TILE_SIZE);
    map_y = (int)(y / TILE_SIZE);
    if (var->map[map_y][map_x] == '1')
        return 0;
    return 1;
}

int check_is_wall(t_start *var, double x, double y)
{
    if (!var || !var->move || !var->map) {
        return -1;
    }

    if (x < 0 || x >= var->move->width_x || y < 0 || y >= var->move->height_y)
        return -1;

    int map_x = (int)(x / TILE_SIZE);
    int map_y = (int)(y / TILE_SIZE);

    if (map_x < 0 || map_x >= var->move->width_x / TILE_SIZE || map_y < 0 || map_y >= var->move->height_y / TILE_SIZE)
        return -1;

    if (var->map[map_y][map_x] == '1')
        return 0;
    if (check_uniq_rays(var, x, y) == 0)
        return 0;
    return 1;
}

void	 git_first_x_intersection(t_start *var)
{
   	double first_intersection_x =0;
	double first_intersection_y =0;
	double xa=0;
	double ya=0;
	double next_intersection_x =0;
	double next_intersection_y =0;

	if(is_looking_up(var->ray->ray_angle))
		first_intersection_y = floor(var->move->coor_y / TILE_SIZE) * TILE_SIZE - 1;
	else if(is_looking_down(var->ray->ray_angle))
		first_intersection_y = floor(var->move->coor_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	
	first_intersection_x = var->move->coor_x + (first_intersection_y - var->move->coor_y) / ( tan(var->ray->ray_angle));


	next_intersection_x = first_intersection_x;
	next_intersection_y = first_intersection_y;
	if(is_looking_up(var->ray->ray_angle))
		ya = -TILE_SIZE;
	else if(is_looking_down(var->ray->ray_angle))
		ya = TILE_SIZE;
	
	xa = ya / tan(var->ray->ray_angle);

	while (check_is_wall(var, next_intersection_x , next_intersection_y) == 1)
	{
		next_intersection_x += xa;
		next_intersection_y += ya;
	}
	var->ray->x_inter_horizontal = next_intersection_x;
	var->ray->y_inter_horizontal = next_intersection_y;
}


void git_first_y_intersection(t_start *var) 
{
	double first_intersection_x =0;
	double first_intersection_y =0;
	double xa=0;
	double ya=0;
	double next_intersection_x =0;
	double next_intersection_y =0;

	if (is_looking_right(var->ray->ray_angle))
		first_intersection_x = floor(var->move->coor_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	else if (is_looking_left(var->ray->ray_angle))
		first_intersection_x = floor(var->move->coor_x / TILE_SIZE) * TILE_SIZE - 1;
	
	first_intersection_y = var->move->coor_y + (first_intersection_x - var->move->coor_x) * tan(var->ray->ray_angle);

	next_intersection_x = first_intersection_x;
	next_intersection_y = first_intersection_y;

	if (is_looking_right(var->ray->ray_angle))
		xa = TILE_SIZE;
	else if (is_looking_left(var->ray->ray_angle))
		xa = -TILE_SIZE;
	
	ya = xa * tan(var->ray->ray_angle);
	while (check_is_wall(var, next_intersection_x , next_intersection_y) == 1)
	{
		next_intersection_x += xa;
		next_intersection_y += ya;
	}
	var->ray->x_inter_vertical = next_intersection_x;
	var->ray->y_inter_vaertical = next_intersection_y;
	
}





void ft_intersection(t_start *var)
{

// printf("+++++++++++++++++++++++++++++++++++++++++++++        \n");

// printf("var->ray->ray_angle         [%f] \n\n\n", rad_to_deg(var->draw->angle));
	
	
var->ray->ray_angle = var->draw->angle  -  deg_to_rad(rad_to_deg(FOV_ANGLE) / 2);
var->ray->ray_angle = normalize_angle(var->ray->ray_angle);
// printf("var->ray->ray_angle         [%f] \n\n\n", rad_to_deg(var->ray->ray_angle));


    int ray =0;
    while (ray <= NUM_RAYS)
    {
        git_first_x_intersection(var);
        git_first_y_intersection(var);
        int  len_a = sqrt(pow(var->ray->x_inter_horizontal - var->move->coor_x , 2) + pow(var->ray->y_inter_horizontal - var->move->coor_y , 2));
        int  len_b = sqrt(pow(var->ray->x_inter_vertical - var->move->coor_x , 2) + pow(var->ray->y_inter_vaertical - var->move->coor_y , 2));

        if (len_a == INT_MIN )
            len_a = 9999;
        if( len_b == INT_MIN)
            len_b = 9999;

        // printf("len_a [%d]  len_b [%d] \n", len_a, len_b);
        if (len_a < len_b)
            drawing_line(var, var->move->coor_x, var->move->coor_y, var->ray->x_inter_horizontal , var->ray->y_inter_horizontal);
        else
            drawing_line(var, var->move->coor_x, var->move->coor_y, var->ray->x_inter_vertical , var->ray->y_inter_vaertical);

        var->ray->ray_angle += deg_to_rad(rad_to_deg(FOV_ANGLE) / NUM_RAYS);
        var->ray->ray_angle = normalize_angle(var->ray->ray_angle);
        ray++;
    }
}
