#include"command.h"
#include"../interfaces/Devices.h"
#include<memory>
class turnoncommand : public command {
public:
std::shared_ptr<devices> devic;
void execute() override;
void undo() override;
turnoncommand(std::shared_ptr<devices> dev);

};