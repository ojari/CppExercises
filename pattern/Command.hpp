struct Command
{
  enum Action { deposit, withdraw } action;
  int amount{0};
  bool success{false};
};

struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    switch (cmd.action)
    {
      case Command::deposit:
        balance += cmd.amount;
        cmd.success = true;
        break;
      case Command::withdraw:
        if (balance >= cmd.amount){
          balance -= cmd.amount;
          cmd.success = true;
        }
        else {
          cmd.success = false;
        }
        break;
    }
  }
};