# ft_printf

Resources:
Va args usage : http://www.cplusplus.com/reference/cstdarg/va_copy/

Modifiers, Specifiers and Flags
% [flags] [width] [.precision] [length] specifier
%c	[ - ] [width] [n/a] [n/a] c
%s	[ - ] [width] [.precision] [n/a] s
%p	[ - ] [width] [n/a] [n/a] p
%d	[ -, 0, space, + ] [width] [.precision] [ l, ll, h, hh ] d 
%i	[ -, 0, space, + ] [width] [.precision] [ l, ll, h, hh ] i
%o	[ -, 0, #  ] [width] [.precision] [ l, ll, h, hh ] o
%u	[ -, 0 ] [width] [.precision] [ l, ll, h, hh ] u
%x	[ -, 0, # ] [width] [.precision] [ l, ll, h, hh ] x
%X	[ -, 0, # ] [width] [.precision] [ l, ll, h, hh ] X
%f	[ - , +, space, 0 ] [width] [.precision] [ l, L] f
%%	[ - ] [width] [n/a] [n/a] %
