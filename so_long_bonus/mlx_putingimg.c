/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putingimg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:03:31 by mmakboub          #+#    #+#             */
/*   Updated: 2022/05/19 22:30:43 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	puting_image(t_compstjeu	*jeu)
{
	char c;
	int	i;
	int	j;

	i = 0;
	while (jeu->map[i])
	{
		j  = 0;
		while (jeu->map[i][j])
		{
	
	 		c = jeu->map[i][j];
			if(c == '0')
				mlx_put_image_to_window(jeu->mlx, jeu->win,	jeu->base_du_sol_img, j * 70 ,i * 70);
			if(c == 'E')
				mlx_put_image_to_window(jeu->mlx, jeu->win,	jeu->exit_img, j * 70 ,i * 70);
			if(c == 'P')
				mlx_put_image_to_window(jeu->mlx, jeu->win,	jeu->joueur_img, j * 70 ,i *70 );
			if(c == '1')
				mlx_put_image_to_window(jeu->mlx, jeu->win,	jeu->mur_img, j * 70 ,i * 70);
			if(c == 'C')
				mlx_put_image_to_window(jeu->mlx, jeu->win,	jeu->collectbls_img, j * 70 ,i * 70);
			if(c == 'M')
			{
				if(rand() % 7 == 0)
				{
					mlx_put_image_to_window(jeu->mlx, jeu->win, jeu->ennemy_img, j * 70, i * 70);
				}
				if(rand() % 15 == 0)
				{
					mlx_put_image_to_window(jeu->mlx, jeu->win, jeu->ennemy1_img, j * 70, i * 70);
				}
				if(rand() % 27 == 0)
				{
					mlx_put_image_to_window(jeu->mlx, jeu->win, jeu->ennemy2_img, j * 70, i * 70);
				}
			}
			j++;
		}
		i++;
	}
	mlx_string_put(jeu->mlx, jeu->win, 70 * jeu->mapsline, 0, \
        0x0000FF, ft_strjoin2("  Moves: ", ft_itoa(jeu->movesnbr)));
}

void	xpmfile_to_image(t_compstjeu *jeu)
{
	int	i;
	int	j;

	i = 70;
	j = 70;
	jeu->mur_img = mlx_xpm_file_to_image(jeu->mlx,"./imags/mure.xpm" , &i, &j);
	jeu->collectbls_img = mlx_xpm_file_to_image(jeu->mlx,"./imags/collectbls.xpm", &i, &j);
	jeu->joueur_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/joueur.xpm", &i, &j);
	jeu->exit_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/exit.xpm", &i, &j);
	jeu->base_du_sol_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/base_du_sol.xpm", &i, &j);
	jeu->ennemy_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/ennemy.xpm", &i, &j);
	jeu->ennemy1_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/ennemy1.xpm", &i, &j);
	jeu->ennemy2_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/ennemy2.xpm", &i, &j);
	jeu->ennemy3_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/ennemy3.xpm", &i, &j);
	jeu->ennemy4_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/ennemy4.xpm", &i, &j);
	jeu->ennemy5_img = mlx_xpm_file_to_image(jeu->mlx, "./imags/ennemy5.xpm", &i, &j);
}