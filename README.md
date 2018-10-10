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

============================

SELECTION:
* CLEAR SCREEN AS RELEVANT
* PRINT ARGUMENTS:
 		* DOUBLE LINKED LIST
			* LINK TO PREVIOUS
			* ARGUMENT STRING
			* BOOL FOR CURRENT
			* BOOL FOR SELECTED
			* LINK TO NEXT
		* IF CURRENT THEN UNDERLINE 
		* IF SELECTED THEN REVERSE VIDEO 
* MOVE CURSOR FROM WORD TO WORD
		* UP: SET CURRENT TO 0 AND DO NEXT (NARG / NLINE) TIMES AND SET CURRENT TO 1
		* DOWN: SET CURRENT TO 0 AND DO PREVIOUS (NARG / NLINE) TIMES AND SET CURRENT TO 1
		* RIGHT: SET CURRENT TO 0 AND DO NEXT ONCE AND SET CURRENT TO 1
		* LEFT: SET CURRENT TO 0 AND DO PREVIOUS ONCE AND SET CURRENT TO 1
* IF SPACE KEY THEN CURRENT.SELECTED = 1 AND REPRINT ALL
* IF DEL OR BACKSPACE KEY THEN REMOVE CURRENT AND REPRINT ALL
* IF ENTER KEY THEN PRINT NODES SELECTED TO STDOUT AND EXIT
* IF ESC KEY THEN EXIT


WINDOW MANAGEMENT:
* WHILE WIN_WIDTH < SIZE OF LINE:
		* NLINE++ 
* PRINT NARG / NLINE PER LINE
* IF WIN_HEIGHT < NLINE PRINT ERROR DISPLAY

SIGNAL MANAGEMENT:
* CATCH QUIT SIGNAL AND CLOSE WITH CLEAN_EXIT IF APPROPRIATE
* INTERRUPT WITH CTL Z AND RESTORE WITH FG

ENV MANAGEMENT:
* IF ENV NOT SET PROPERLY, DISPLAY ERROR ENV
