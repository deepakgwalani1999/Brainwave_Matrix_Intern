# Brainwave_Matrix_Intern
## ATM Interface Code
Hello Guyz Hope You are well and safe .I had made this code of atm all by myself.

## KEY POINTS:
1. Code is fully based on C++ file handling
2. Code is have 3 text file that would be generated automatically  when code proceeds and delete as well
3. Code will work for version less than c++ 11. Because there are many  libraries that i was unable to handle.
4. Code is for single usage and dont store data for multiple users.
5. I had not that much time so i generated otp in text format in file in program itself...SORRY FOR THAT!! :) 

## Working.
### Step1: 
Code ask for the Card Registrationn in ATM.Same like inserting the card in atm slot.
So first option is if you haven't made your card inserted or registered then make it.In this you would be asked for.
1.Card last 4 digit(For convinience)
2.DOB(Date Of Birth)
3.Card Holder Name
4.Pin
5.Balance
And if you have already registered than insert a card and say already have account.Now if you are already registered then you have you information saved in file(for single user i say).But when the info is stored in file and you register than that files and transactions would get deleted.

## Step2:
Now you have Options After registration or already registered.
1. Withdraw Money
2. Account Details
3. Forgot Pin
4. Exit
#### Withdraw Money
In this user will withdraw Money By simply entering the pin and if pin matches the user info stored in file then program will ask to enter the money to withdraw .
After the money  withdraw the amount left will be updated in file **"Users.txt"** the file that stores user information and also  the history will get stored in 
**Transaction.txt** .I only made *savings account* module here. Also number of Transactions are limited.

#### Account Details
In this we have two types of details.
**Transaction Details** =The Details  about history of particular users.
**Personal Details**= That stores the personal details of user having information about users.It can only open after we authenticate with pin.

## Step3:
I considered that user don't have card number written on card just plain card. So if you forgot pin .You must know your card last 4 digits.
That will authenticate user and OTP is generated then a text file will be generated that **OTP.txt** in which generated otp comes.Here we will see the 
otp and write it in the otp section of console if otp is correct than the pin would be displayed.

## Step4:
Exiting the programe makes us to come out of program.

# Things I Forgot
1. To give back option
2. To make timer.I tried but chrono which was library was not working (working for c++ 11 or higher)
3. With that i had to make separate thread
4. I used information which was not as preety much as useful information.You can change the information with your convinience.

Anyways i am leaving this code in main file and making it public any enhancement would be further appreciated.And with new version make a branch of it and commit here.

** This is Deepak Gwalani  Signing Off from this Project **
** Thankyou**








   

