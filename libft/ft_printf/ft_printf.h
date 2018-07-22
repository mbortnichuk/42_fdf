/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:04:56 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/12 15:59:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

# define RC "\x1B[0m"
# define BOLD	"\e[1m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"

/*
** ft_printf prototype
*/
int					ft_printf(const char *format, ...);

/*
** Printf intel gaining structure.
*/
typedef struct		s_intel
{
	int		width;
	int		precision;
	int		flags;
}					t_intel;

/*
** Defines for all specifiers
*/
# define SPECS		"sSpdDioOuUxXcC"
# define SPECSCOUNT	(ft_strlen(SPECS))

/*
** Encoding used for the SPECS macro string
*/
# define STRING 	(0)
# define WSTRING 	(1)
# define POINTER	(2)
# define LOWD		(3)
# define UPPD		(4)
# define LOWI		(5)
# define LOWO		(6)
# define UPPO 		(7)
# define LOWU 		(8)
# define UPPU 		(9)
# define LOWX 		(10)
# define UPPX 		(11)
# define LOWC 		(12)
# define UPPC 		(13)

/*
** Macro function to shift x 1 bit to the left
*/
# define FBIT(x)	(1 << (x))

/*
** Encoding every single attribute of printf,
** representing one bit for every single one of them.
*/
# define STRING_B 	(FBIT(0))
# define WSTRING_B	(FBIT(1))
# define POINTER_B 	(FBIT(2))
# define LOWD_B 	(FBIT(3))
# define UPPD_B		(FBIT(4))
# define LOWI_B		(FBIT(5))
# define LOWO_B		(FBIT(6))
# define UPPO_B		(FBIT(7))
# define LOWU_B		(FBIT(8))
# define UPPU_B		(FBIT(9))
# define LOWX_B		(FBIT(10))
# define UPPX_B		(FBIT(11))
# define LOWC_B		(FBIT(12))
# define UPPC_B		(FBIT(13))

# define SHARP		(FBIT(14))
# define ZERO		(FBIT(15))
# define PLUS		(FBIT(16))
# define MINUS		(FBIT(17))
# define SPACE		(FBIT(18))

# define HH			(FBIT(19))
# define H			(FBIT(20))
# define L			(FBIT(21))
# define LL			(FBIT(22))
# define J			(FBIT(23))
# define Z			(FBIT(24))

# define WIDTH		(FBIT(25))
# define PREC		(FBIT(26))

/*
** Macro to check whether memory was allocated, if not - returns 0.
*/
# define CHECK(x) if (!x) return (0);

/*
** ft_handle_str.c
*/
int					ft_str(t_intel *intel, va_list arg);
int					ft_chr(t_intel *intel, va_list ap);

/*
** ft_handle_wchr.c
*/
int					ft_wchrlen(wchar_t c);
int					ft_wstrlen(wchar_t *wc);
int					wchrutf8(char *res, wchar_t c);
int					ft_putwchr(wchar_t c);
int					ft_wchr(t_intel *intel, va_list arg);

/*
** ft_handle_wstr.c
*/
wchar_t				*ft_wcsnew(size_t len);
wchar_t				*ft_wcsncpy(wchar_t *new, wchar_t *str, size_t len);
wchar_t				*ft_wcscpy(wchar_t *new, wchar_t *str);
wchar_t				*ft_wcsdup(wchar_t *str);
int					ft_wstr(t_intel *intel, va_list arg);

/*
** ft_handle_hexadec.c
*/
char				*is_hex_n(char *hex, char *hstr, uintmax_t number);
int					hex_dig(uintmax_t number);
char				*convert_to_hex(uintmax_t number, int *nbr);
int					ft_hex(t_intel *intel, va_list arg);

/*
** ft_handle_octal.c
*/
char				*convert_to_oct(uintmax_t n, int *nbr);
int					ft_oct(t_intel *intel, va_list arg);

/*
** ft_val_unsig.c
*/
int					ft_notnbr(int intel, int p, uintmax_t n);
int					zerosfornbr(t_intel *intel, int mark, int *i);
int					spacesfornbr(int *i, int intel, int widthminimal);
char				*unsigned_nbr(uintmax_t n, int *nbr, int base);
int					ft_unsigned(uintmax_t n, t_intel *intel, \
						char*(*modif)(uintmax_t, int*));

/*
** ft_val_sign.c
*/
void				ft_putunsignbr(uintmax_t number);
int					how_many_digs(intmax_t number);
void				sign_printing_func(intmax_t number, int intel);
int					ft_signed(intmax_t number, t_intel *intel);

/*
** ft_handle_decimals.c
*/
char				*convert_to_decimal(uintmax_t number, int *nbr_arr);
int					s_decimal(t_intel *intel, va_list arg);
int					u_decimal(t_intel *intel, va_list arg);
int					ft_number(t_intel *intel, va_list arg);

/*
** ft_output.c
*/
int					print_all(t_intel *intel, va_list ap, char frm, int i);
int					to_output(const char *frm[], va_list ap);
int					ft_print_space(int w, int i, int intel);
int					ft_print_nothing(t_intel *intel, char c);

/*
** ft_specif.c
*/
int					specpos(char *specifier, char c);
int					findspec(t_intel *intel, char *specifier, char c);
int					parsespec(t_intel *intel, va_list ap, char **frm);

/*
** ft_flags.c
*/
int					length(t_intel *intel, char *frm);
int					flags(t_intel *intel, char c);
int					width(t_intel *intel, va_list ap, char *frm);
int					precision(t_intel *intel, va_list arg, char *frm);
int					get_all_fl(t_intel *intel, va_list ap, char **frm);

/*
** ft_auxiliary_func1.c
*/
int					ft_putwnstr(wchar_t *ws, size_t len);
int					ft_putwstr(wchar_t *wstr);
char				*ft_tolowstr(char *str);

/*
** ft_auxiliary_func2.c
*/
void				ft_putnstr(char const *s, size_t len);
void				ft_putnchar(char c, int t);
char				*ft_strrev(char *str);

#endif
