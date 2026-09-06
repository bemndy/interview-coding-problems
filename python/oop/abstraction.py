# Abstraction 

# Reduce complexity by hiding unnecessary details

class EmailService:
    def _connect(self):
        print("connecting to email server...")

    def _authenticate(self):
        print("authenticating...")

    def send_email(self):
        self._connect()
        self._authenticate()
        print("sending email...")
        self._disconnect()

    def _disconnect(self):
        print("disconnecting from email server...")

email = EmailService()
email.send_email()

## again we use abstraction to allow for modularity and 
## easier access from user to use functions without interacting
## with functions/logic within. 

## differences between encapsulation

# encapsulation gets at setting private and protected properties within a class
# is supposed to support abstraction, the actual methods being used to do that are
# setter, getter, private and protected methods/variables

# abstraction is just the idea that we are reducing this internal complexity to the user
# what object does rather than how it does it

