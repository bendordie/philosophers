# philosophers

Dining philosopher's problem solution

# About

This project is aimed at learning the basics of threading a process.

Here are the things you need to know about this task:

• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.

• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.

• Every philosopher needs to eat and should never starve.

• Philosophers don’t speak with each other.

• Philosophers don’t know if another philosopher is about to die.

• No need to say that philosophers should avoid dying!


The main difference between philo and philo_bonus is that the former uses mutex to solve the deadlock situation and the latter uses semaphores.

# Getting started

Choose one of two realisation: bonus (semaphores) or not (mutexes) and run make in choosen directory.

Then for example: <code>./philo 5 800 200 200 7</code>

Parameters:

1. Number of philosophers (threads)
2. Time to live in usec
3. Time to eat in usec
4. Time to sleep in usec
5. Number of times each philosopher must eat

For more details please watch <code>en.subject.pdf</code>.
