#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "cub3d.h"

// color.c
int					get_color(t_color color);
unsigned int		*get_img_colors(t_img img);
t_color				*new_color(t_string	input_color);
unsigned int		get_img_color(t_img img, int x, int y);
void				print_color(t_color *color, t_string name);

// textures.c
t_img				img_init(void *mlx, char *addr);
void				textures_init(t_data *data);

// sprites.c
t_animated_sprite	get_animated_sprite(t_data *data, int letter);
unsigned int		get_animated_sprite_color(char letter,
						t_data *data, int x, int y);
t_sprite_info		new_sprite_info(int x, int y, int texture);

// get_next_line
t_string			ft_substr(const t_string s, unsigned int start, size_t len);
t_string			get_next_line(int fd);

// text_utils.c
int					text_len(t_text text);

// str_utils.c
t_string			ft_strdup(t_string const s1);
t_string			ft_strjoin(t_string const s1, t_string const s2);
size_t				ft_strlen(t_string const s);
t_bool				contains(t_string str, char ch);
t_bool				is_empty_line(t_string line);
t_bool				starts_with_string(t_string str1, t_string str2);
t_bool				starts_with(t_string token, char start);
t_bool				ft_strcmp(t_string s1, t_string s2);
t_bool				is_numeric_string(t_string str);
t_bool				is_unsigned_char(t_string str);
t_bool				str_contains_only(t_string word, t_string charset);
t_bool				has_extention(t_string path, t_string extention);

// free.c
void				ft_free(void *data);
void				guard_free(t_string str);
void				free_array(t_text arr);

// ft_split.c
t_text				ft_split(t_string const s, char c);

// printer.c
void				print_error(int error_code);
void				set_color(t_string color, int fd);
void				print_error_and_exit(int error_code);
void				print_error_free_and_exit(t_data *data, int error_code);

// atoi.c
unsigned char		basic_atouc(t_string str);

#endif
