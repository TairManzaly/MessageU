class Messages:
    def __init__(self, messID, reciever, sender, Type, Content):
        self.messID = messID
        self.ToClient = reciever
        self.FromClient = sender
        self.Type = Type
        self.Content = Content

        