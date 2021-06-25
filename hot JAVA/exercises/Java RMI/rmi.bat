@echo off 
@rem these are meant for windows. they have not been tested with other platforms

TITLE RMI example
start rmic myRMIImpl
start rmiregistry
start java theServer
@rem this part above is meant to be run on remote server, we run it on local computer for testing purposes

ECHO RMI stub started
@rem java myRMIClient 127.0.0.1 variable variable 
@rem or your ip address

ECHO success
