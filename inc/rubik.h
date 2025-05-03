#ifndef RUBIK_H
# define RUBIK_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

#define NUM_FACES 6
#define SIZE 4

#define WHITE  'W'
#define RED    'R'
#define GREEN  'G'
#define YELLOW 'Y'
#define ORANGE 'O'
#define BLUE   'B'

typedef struct s_cube {
	char **face;
} t_cube;

typedef enum e_face
{
    U = 0,
    R = 1,
    F = 2,
    D = 3,
    L = 4,
    B = 5
} t_face;

//utils
void	print_cube(const t_cube *cube);
void	ft_free(t_cube *cube);
int	get_face_index(char face);
void	get_modifiers(char *mov, int *is_prime, int *is_double);

//apply input
void	apply_moves(t_cube *cube, char *input);
void	move(t_cube *cube, char *move);
int	next_move(char *str, int *i, char *move);
void	apply_adjacent(t_cube *cube, char face, int is_prime, int is_double);
void	rotate_face(t_cube *cube, int face_index, int is_prime, int is_double);


//face moves
void	rotate_face_clockwise(char *f);
void	rotate_face_counterclockwise(char *f);
void	rotate_face_180(char *f);

//moves
void	move_F(t_cube *c);
void	move_D(t_cube *c);
void	move_R(t_cube *c);
void	move_L(t_cube *c);
void	move_B(t_cube *c);

#endif
