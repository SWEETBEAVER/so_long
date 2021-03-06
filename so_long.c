/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:09:40 by mmakboub          #+#    #+#             */
/*   Updated: 2022/05/17 23:13:43 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// int fun(t_compstjeu *jeu)
// {
// 	return 0 ;
// }
void ft_initializingvariabls(t_compstjeu *jeu)
{
	jeu->joueur = 0;
	jeu->collectbls = 0;
	jeu->exit = 0;
	jeu->mapsline = 0;
	jeu->map = NULL;
	jeu->abscisse = 0;
	jeu->ordonnee = 0;
	jeu->movesnbr = 0;
}

void	free_map(t_compstjeu *jeu)
{
	int	i;

	i = 0;
	while (jeu->map[i])
	{
		free(jeu->map[i]);
		i++;
	}
	 free(jeu->map);
}

int	quittekey17(int keycode, t_compstjeu *jeu)
{
	(void)keycode;
	//perror("fin kain lerror!!\n");

	// while (i < jeu->mapsline)
	// 	free(jeu->map[i++]);
	// free(jeu->map);
	exit(0);
	return (0);
}

int main(int argc, char *argv[])
{
	t_compstjeu jeu;
	char *file;
	int i = 0;
	
	ft_initializingvariabls(&jeu);
	if (argc != 2)
	{
		ft_putstr("invalide argument");
		return(1);
	}
	file = argv[1];
	ft_check_ber(file);
	int read = ft_readline_maps(&jeu, argv[1]);
	i = 0;
	/*while (jeu.map[i]) {
		printf("%s", jeu.map[i]);
		i++;
	}*/
	if (!read)
		ft_putstr("there is an error on map");
	ft_reading_intern_map(&jeu);
	//int b1, b2, b3, b4, b5;
	//b1 = b2 = b3 = b4 = b5 = 1;
	if (!(ft_check_map_form(&jeu)) || !(ft_check_lines_extremity(&jeu)) || !(ft_check_maps_content(&jeu)) || !(ft_checkfirst_lastline(&jeu)))
	{
		ft_putstr("there is an error in map that u should fixe it\n");
		//printf("%d %d %d %d\n", b1, b2, b3, b4);
		return 1;
	}
	jeu.mlx = mlx_init();
	jeu.win = mlx_new_window(jeu.mlx, ft_strlen(jeu.map[jeu.mapsline - 1]) * 70, jeu.mapsline * 70, "so_long");
	printf("len === %d\n",ft_strlen(jeu.map[0]));
	xpmfile_to_image(&jeu);
	//mlx_key_hook(jeu.win, checking_keys, &jeu);
	puting_image(&jeu);
	mlx_hook(jeu.win, 2, 1L<<0, checking_keys, &jeu);
	mlx_hook(jeu.win, 17, 1L, quittekey17, &jeu);
	// mlx_loop_hook(jeu.mlx, &fun,&jeu);
	// puting_image(&jeu);
	mlx_loop(jeu.mlx);
	return 0;
}