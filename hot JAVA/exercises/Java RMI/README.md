**LINUX RHEL.** should work for debian or ubuntu as well.
1. rmic theImp
2. rmiregistry &
3. either java myRMIServer or use screen command if you do not wish to use an extra terminal. please google.
4. java myRMIClient

**WINDOWS**
compile by typing ***javac \*.java using command prompt at directory where files are located.***
1. rmic theImp
2. start rmiregistry
3. java theServer
4. java myRMIClient 127.0.0.1 or remote ip address and 2 variables
5. e.g. java myRMIClient 127.0.0.1 5 12

**OR**

type rmi.bat
then 
java myRMIClient 127.0.0.1  1st variable 2nd variable
e.g. java myRMIClient 127.0.0.1 50 256
