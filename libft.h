/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:28:20 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/24 17:32:52 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define BUFF_SIZE 32

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Part 1: Fonctions de la libc
*/

void			*ft_memset(void *s, int c, size_t n);
/*
** La fonction memset() remplit les n premiers octets de la zone mémoire
** pointée par s avec l'octet c.
*/

void			ft_bzero(void *s, size_t n);
/*
** La fonction bzero() met à 0 (octets contenant « \0 ») les n premiers octets
** du bloc pointé par s.
*/

void			*ft_memcpy(void *dest, const void *src, size_t n);
/*
** La fonction memcpy() copie n octets depuis la zone mémoire src vers la
** zone mémoire dest.
*/

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
/*
** La fonction memccpy() copie au plus n octets de la zone mémoire src vers la
** zone mémoire dest, s'arrêtant dès qu'elle rencontre le caractère c.
*/

void			*ft_memmove(void *dest, const void *src, size_t n);
/*
** La fonction memmove() copie n octets depuis la zone mémoire src vers la zone
** mémoire dest. Les deux zones peuvent se chevaucher : la copie se passe comme
** si les octets de src étaient d'abord copiés dans une zone temporaire qui ne
** chevauche ni src ni dest, et les octets sont ensuite copiés de la zone
** temporaire vers dest.
*/

void			*ft_memchr(const void *s, int c, size_t n);
/*
** La fonction memchr() examine les n premiers octets de la zone mémoire pointée
** par s à la recherche du caractère c. Le premier octet correspondant à c
** (interprété comme un unsigned char) arrête l'opération.
*/

int				ft_memcmp(const void *s1, const void *s2, size_t n);
/*
** La fonction memcmp() compare les n premiers octets des zones mémoire s1 et
** s2. Elle renvoie un entier inférieur, égal, ou supérieur à zéro, si s1 est
** respectivement inférieure, égale ou supérieur à s2.
*/

size_t			ft_strlen(const char *str);
/*
** La fonction strlen() calcule la longueur de la chaîne de caractères s, sans
** compter l'octet nul « \0 » final.
*/

char			*ft_strdup(const char *src);
/*
** La fonction strdup() renvoie un pointeur sur une nouvelle chaîne de
** caractères qui est dupliquée depuis s. La mémoire occupée par cette nouvelle
** chaîne est obtenue en appelant malloc(3), et peut (doit) donc être libérée
** avec free(3).
*/

char			*ft_strcpy(char *dest, const char *src);
/*
** La fonction strcpy() copie la chaîne pointée par src (y compris l'octet nul
** « \0 » final) dans la chaîne pointée par dest. Les deux chaînes ne doivent
** pas se chevaucher. La chaîne dest doit être assez grande pour accueillir la
** copie.
*/

char			*ft_strncpy(char *dest, const char *src, size_t n);
/*
** La fonction strncpy() est identique, sauf que seuls les n premiers octets de
** src sont copiés.
*/

char			*ft_strcat(char *dest, const char *src);
/*
** La fonction strcat() ajoute la chaîne src à la fin de la chaîne dest en
** écrasant le caractère nul (« \0 ») à la fin de dest, puis en ajoutant un
** nouveau caractère nul final. Les chaînes ne doivent pas se chevaucher, et la
** chaîne dest doit être assez grande pour accueillir le résultat.
*/

char			*ft_strncat(char *dest, const char *src, size_t n);
/*
** La fonction strncat() est identique, à la différence qu'elle ne prend en
** compte que les n premiers caractères de src et src n'a pas besoin d'octet
** nul final si elle contient n caractères ou plus.
*/

size_t			ft_strlcat(char *dest, const char *src, size_t size);

char			*ft_strchr(const char *str, int c);
/*
** La fonction strchr() renvoie un pointeur sur la première occurrence du
** caractère c dans la chaîne s
*/

char			*ft_strrchr(const char *str, int c);
/*
** La fonction strrchr() renvoie un pointeur sur la dernière occurrence du
** caractère c dans la chaîne s.
*/

char			*ft_strstr(const char *str, const char *to_find);
/*
** La fonction strstr() cherche la première occurrence de la sous-chaîne
** to_find au sein de la chaîne str. Les caractères « \0 » de fin ne sont pas
** comparés.
*/

char			*ft_strnstr(const char *str, const char *to_find, size_t len);

int				ft_strcmp(const char *s1, const char *s2);
/*
** La fonction strcmp() compare les deux chaînes s1 et s2. Elle renvoie un
** entier négatif, nul, ou positif, si s1 est respectivement inférieure, égale
** ou supérieure à s2.
*/

int				ft_strncmp(const char *s1, const char *s2, size_t n);
/*
** La fonction strncmp() est identique sauf qu'elle ne compare que les n
** (au plus) premiers caractères de s1 et s2.
*/

int				ft_atoi(const char *str);
/*
** La fonction atoi() convertit le début de la chaîne pointée par str en
** entier de type int .
*/

int				ft_isalpha(int c);
/*
** La fonction isalpha() vérifie si l'on a un caractère alphabétique.
*/

int				ft_isdigit(int c);
/*
** La fonction isdigit() vérifie si l'on a un chiffre (0 à 9).
*/

int				ft_isalnum(int c);
/*
** La fonction isalnum() vérifie si l'on a un caractère alphanumérique.
*/

int				ft_isascii(int c);
/*
** La fonction isascii() vérifie si c est un unsigned char sur 7 bits, entrant
** dans le jeu de caractères ASCII.
*/

int				ft_isprint(int c);
/*
** La fonction isprint() vérifie s'il s'agit d'un caractère imprimable, y
** compris l'espace.
*/

int				ft_toupper(int c);
/*
** La fonction toupper() convertit la lettre c en majuscule si c'est possible.
*/

int				ft_tolower(int c);
/*
** La fonction tolower() convertit la lettre c en minuscule si c'est possible.
*/

/*
** Part 2: Fonctions supplémentaires
*/

void			*ft_memalloc(size_t size);
/*
** Alloue (avec malloc(3)) et retourne une zone de mémoire “fraiche”. La mémoire
** allouée est initialisée à 0. Si l’allocation échoue, la fonction renvoie
** NULL.
*/

void			ft_memdel(void **ap);
/*
** Prend en paramètre l’adresse d’un pointeur dont la zone pointée doit être
** libérée avec free(3), puis le pointeur est mis à NULL.
*/

char			*ft_strnew(size_t size);
/*
** Alloue (avec malloc(3)) et retourne une chaîne de caractère “fraiche”
** terminée par un ’\0’. Chaque caractère de la chaîne est initialisé à ’\0’. Si
** l’allocation echoue, la fonction renvoie NULL.
*/

void			ft_strdel(char **as);
/*
** Prend en paramètre l’adresse d’une chaîne de caractères qui doit être libérée
** avec free(3) et son pointeur mis à NULL.
*/

void			ft_strclr(char *s);
/*
** Assigne la valeur ’\0’ à tous les caractères de la chaîne passée en
** paramètre.
*/

void			ft_striter(char *s, void (*f)(char *));
/*
** Applique la fonction f à chaque caractère de la chaîne de caractères passée
** en paramètre. Chaque caractère est passé par adresse à la fonction f afin de
** pouvoir être modifié si nécessaire.
*/

void			ft_striteri(char *s, void (*f)(unsigned int, char *));
/*
** Applique la fonction f à chaque caractère de la chaîne de caractères passée
** en paramètre en précisant son index en premier argument. Chaque caractère est
** passé par adresse à la fonction f afin de pouvoir être modifié si nécessaire.
*/

char			*ft_strmap(char const *s, char (*f)(char));
/*
** Applique la fonction f à chaque caractère de la chaîne de caractères passée
** en paramètre pour créer une nouvelle chaîne “fraiche” (avec malloc(3))
** résultant des applications successives de f.
*/

char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
/*
** Applique la fonction f à chaque caractère de la chaîne de caractères passée
** en paramètre en précisant son index pour créer une nouvelle chaîne “fraiche”
** (avec malloc(3)) résultant des applications successives de f.
*/

int				ft_strequ(char const *s1, char const *s2);
/*
** Compare lexicographiquement s1 et s2. Si les deux chaînes sont égales, la
** fonction retourne 1, ou 0 sinon.
*/

int				ft_strnequ(char const *s1, char const *s2, size_t n);
/*
** Compare lexicographiquement s1 et s2 jusqu’à n caractères maximum ou bien
** qu’un ’\0’ ait été rencontré. Si les deux chaînes sont égales, la fonction
** retourne 1, ou 0 sinon.
*/

char			*ft_strsub(char const *s, unsigned int start, size_t len);
/*
** Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un tronçon de la
** chaîne de caractères passée en paramètre. Le tronçon commence à l’index start
** et a pour longueur len. Si start et len ne désignent pas un tronçon de chaîne
** valide, le comportement est indéterminé. Si l’allocation échoue, la fonction
** renvoie NULL.
*/

char			*ft_strjoin(char const *s1, char const *s2);
/*
** Alloue (avec malloc(3)) et retourne une chaîne de caractères “fraiche”
** terminée par un ’\0’ résultant de la concaténation de s1 et s2. Si
** l’allocation echoue, la fonction renvoie NULL.
*/

char			*ft_strtrim(char const *s);
/*
** Alloue (avec malloc(3)) et retourne une copie de la chaîne passée en
** paramètre sans les espaces blancs au debut et à la fin de cette chaîne.
** On considère comme espaces blancs les caractères ’ ’, ’\n’ et ’\t’. Si s ne
** contient pas d’espaces blancs au début ou à la fin, la fonction renvoie une
** copie de s. Si l’allocation echoue, la fonction renvoie NULL.
*/

char			**ft_strsplit(char const *s, char c);
/*
** Alloue (avec malloc(3)) et retourne un tableau de chaînes de caractères
** “fraiches” (toutes terminées par un ’\0’, le tableau également donc)
** résultant de la découpe de s selon le caractère c. Si l’allocation echoue,
** la fonction retourne NULL. Exemple :
** ft_strsplit("*salut*les***etudiants*", ’*’) renvoie le tableau
** ["salut", "les", "etudiants"].
*/

char			*ft_itoa(int n);
/*
** Alloue (avec malloc(3)) et retourne une chaîne de caractères “fraiche”
** terminée par un ’\0’ représentant l’entier n passé en paramètre. Les nombres
** négatifs doivent être gérés. Si l’allocation échoue, la fonction renvoie
** NULL.
*/

void			ft_putchar(char c);
/*
** Affiche le caractère c sur la sortie standard.
*/

void			ft_putstr(char const *s);
/*
** Affiche la chaîne s sur la sortie standard.
*/

void			ft_putendl(char const *s);
/*
** Affiche la chaîne s sur la sortie standard suivi d’un ’\n’.
*/

void			ft_putnbr(int n);
/*
** Affiche l’entier n sur la sortie standard.
*/

void			ft_putchar_fd(char c, int fd);
/*
** Ecrit le caractère c sur le descripteur de fichier fd.
*/

void			ft_putstr_fd(char const *s, int fd);
/*
** Ecrit la chaîne s sur le descripteur de fichier fd.
*/

void			ft_putendl_fd(char const *s, int fd);
/*
** Ecrit la chaîne s sur le descripteur de fichier fd suivi d’un ’\n’.
*/

void			ft_putnbr_fd(int n, int fd);
/*
** Ecrit l’entier n sur le descripteur de fichier fd.
*/

/*
** Partie bonus
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
/*
** Alloue (avec malloc(3)) et retourne un maillon “frais”. Les champs content et
** content_size du nouveau maillon sont initialisés par copie des paramètres de
** la fonction. Si le paramètre content est nul, le champs content est
** initialisé à NULL et le champs content_size est initialisé à 0 quelque soit
** la valeur du paramètre content_size. Le champ next est initialisé à NULL. Si
** l’allocation échoue, la fonction renvoie NULL.
*/

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et libère la
** mémoire du contenu de ce maillon avec la fonction del passée en paramètre
** puis libère la mémoire du maillon en lui même avec free(3). La mémoire du
** champ next ne doit en aucun cas être libérée. Pour terminer, le pointeur sur
** le maillon maintenant libéré doit être mis à NULL (de manière similaire à la
** fonction ft_memdel de la partie obligatoire).
*/

void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et libère la
** mémoire de ce maillon et celle de tous ses successeurs l’un après l’autre
** avec del et free(3). Pour terminer, le pointeur sur le premier maillon
** maintenant libéré doit être mis à NULL (de manière similaire à la fonction
** ft_memdel de la partie obligatoire).
*/

void			ft_lstadd(t_list **alst, t_list *new);
/*
** Ajoute l’élément new en tête de la liste.
*/

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction f.
*/

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
** Parcourt la liste lst en appliquant à chaque maillon la fonction f et crée
** une nouvelle liste “fraiche” avec malloc(3) résultant des applications
** successives. Si une allocation échoue, la fonction renvoie NULL.
*/

/*
** Partie personnelle
*/

int				ft_sqrt(int nb);

void    		ft_free_tab(void **tab, size_t len);

int				get_next_line(int fd, char **line);

#endif
