# ft_select
"This project is meant to make you code a small program using termcaps which will allow you to pick from a list of choices and return it to your shell."

## Allowed functions:

* isatty: determine if _fd_ refers to a valid terminal type device
* ttyname: get the name of terminal if __isatty()__ is true
* ttyslot: returns the number of the line that describes the controlling terminal (see __ttys__)
* ioctl: can change terminal charateristics
* getenv: return a pointer to the value of the environment variable _name_
* tcsetattr: change the parameters of the terminal from the termios structure passed as argument
* tcgetattr: save the current parameters of the terminal in the termios struct passed as argument
* tgetent: those functions seems to be used to know the capabilities of the terminal
* tgetflag: _see above_
* tgetnum: _see above_
* tgetstr: _see above_
* tgoto: _see above_
* tputs: _see above_
* open, close, write
* malloc, free
* read, exit
* signal

AND the __termcap__ library.
