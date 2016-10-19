# CS 104 Student Repository

- **Name**: Rohan Chakraborty
- **USC ID**: 1233719421
- **Email**: rmchakra@usc.edu

Changes I need to make

Read up on
		QLabel
		QRadioButton
		QPushButton
		QLineEdit
		QSlider
		QSpinBox
		QComboBox
		QMessageBox
		most of the layouts
		probably some others

		simple windows with dialogs, connecting signals with slots, and overloading the display and actions of buttons.
		
error happens during startup
		write an error message to cout and terminate
		no need to pop up a window for that
Board class
		Imherit the orig board class publicly and make the print a virtual function. Overwrite it to be a GUI and in orig change the variables

window for moves
		At each move pop up a window asking which move should be carried out
Buttons for each move at each turn which can be clicked on
When a user enters an illegal move
		pop up a window informing the user of this (and what was wrong with the move), and when the user presses "Ok" or "Confirm" or "Close", you should return to let the user enter another move instead.
When game is over
		you should perform the final score adjustments, show those adjustments to the users, and display the final scores and the winner(s), as before. Once the users
		confirm this window, the game should terminate.
For place function
		starting square of your move must be determined by clicking on the board. So you cannot enter board coordinates anywhere
		radio buttons to select the direction
		deal with blanks? When using one, you might pop up a window to select the letter to use it as.
		To select a tile have one board display object woth numerous buttons,
		each button gives a signal as to the place of that button
		That position is passed to actually perform the moves

For exchange
		simply have a box in which you enter the tiles to be exchanged

