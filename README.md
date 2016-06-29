#Project-E-Manager
This project aims to create a command line program for funds in a particular year. The idea is to manage your expenses on a weekly basis instead of spending heavily in the first half and then living like a pauper in the second.

##Features of the Application
1. Initially the ‘Pocket Money’ for the entire money will be given before the first day of the month.

2. Assuming a month to be of 4 weeks, the weeks will be categorised into 3 sub-categories.
i. High-spending week (1 week) – 35% of the budget
ii. Moderate spending weeks (2 weeks) – 50% of the budget (25 – 25 split)
iii. Low spending week (1 week) – 15% of the budget

3. The priority weeks will be decided at the beginning of the month by the user.

4. The days in the week will further be categorised into weekdays and weekends ... idea being weekends usually have higher cost rates than weekdays.

5. If you over-spend for a week, in addition to the money you over spent 5% of your budget for the next high-priority week is cut from the budget as a penalty for over-spending.

Example: If the user has spent ₹3000 in a LS week(Week 1) where s/he had to spend ₹1500 and a HS week(₹3500) is scheduled at Week 3, then ₹1500 will be deducted from the HS week and 5%(i.e. ₹100 from the remaining ₹2000) will be deducted as well.

6. Cash remaining at the end of the week should be added to the savings account at the end of the week.  

 ##Versions Of the Application

v0.1 Memory life of only one month. Accounts can be added for a validity of a month and then at the end of the month the account will display the amount of money in the savings account of the applicant.
