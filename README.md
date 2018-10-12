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

## TO DO:

- [x] put terminal in raw mode
- [x] do not echo stdin
- [x] move cursor

----------------------------------

###	Selection:
* ~~clear screen as relevant~~
* ~~print arguments:~~
	* ~~double linked list~~
	* ~~link to previous~~
	* ~~argument string~~
	* ~~bool for current~~
	* ~~bool for selected~~
	* ~~link to next~~
	* ~~if current then underline~~
	* ~~if selected then reverse video~~ 
* ~~move cursor from word to word~~
	* ~~up: set current to 0 and do next (narg / nline) times and set current to 1~~
	* ~~down: set current to 0 and do previous (narg / nline) times and set current to 1~~
	* ~~right: set current to 0 and do next once and set current to 1~~
	* ~~left: set current to 0 and do previous once and set current to 1~~
* ~~if space key then current.selected = 1 and reprint all~~
* ~~if del or backspace key then remove current and reprint all~~
* ~~if enter key then print nodes selected to stdout and exit~~
* ~~if esc key then exit~~


### Window management:
* ~~while win_width < size of line:~~
	* ~~nline++~~
* ~~print narg / nline per line~~
* ~~if win_height < nline print error display~~
* find a way to update on resizing even if no key is pressed

### Signal management:
* catch quit signal and close with clean_exit if appropriate
* interrupt with ctl z and restore with fg

### Env management:
* if env not set properly, display error env

### Input keys:
* ~~handle arrows and del/backspace~~

### Exit:
* create proper exit function and use for each appropriate event
