#include "Message_Structure.h"

// CU_Message -- Public Functions /////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
    Constructor -- Default
*/
CU_Message::CU_Message()
{
    nSequenceNum = nHashCompare = 0;

    stStatus.bOperation_En = 0;
    stStatus.bMotor_x_En = 0;
    stStatus.bMotor_y_En = 0;
    stStatus.bMotor_z_En = 0;

    fPosition_x_cmd = fPosition_y_cmd = fPosition_z_cmd = 0;
    fVelocity_x_cmd = fVelocity_y_cmd = fVelocity_z_cmd = 0;
}

/*-------------------------------------------------------------------------------------------------
    Constructor -- Accepts CU_Message_Structure_Normal_T structure
*/
CU_Message::CU_Message(CU_Message_Structure_Normal_T & stMessage)
{
    nSequenceNum = stMessage.nSequenceNum;

    stStatus.bOperation_En = stMessage.stStatus.bOperation_En;
    stStatus.bMotor_x_En = stMessage.stStatus.bMotor_x_En;
    stStatus.bMotor_y_En = stMessage.stStatus.bMotor_y_En;
    stStatus.bMotor_z_En = stMessage.stStatus.bMotor_z_En;

    fPosition_x_cmd = stMessage.fPosition_x_cmd;
    fPosition_y_cmd = stMessage.fPosition_y_cmd;
    fPosition_z_cmd = stMessage.fPosition_z_cmd;
    fVelocity_x_cmd = stMessage.fVelocity_x_cmd;
    fVelocity_y_cmd = stMessage.fVelocity_y_cmd;
    fVelocity_z_cmd = stMessage.fVelocity_z_cmd;
}

/*-------------------------------------------------------------------------------------------------
    Constructor -- Accepts CU_Message_Structure_Recovery_T structure
*/
CU_Message::CU_Message(CU_Message_Structure_Recovery_T & stMessage)
{
    nSequenceNum = stMessage.nSequenceNum;

    stStatus.bOperation_En = 0;
    stStatus.bMotor_x_En = 0;
    stStatus.bMotor_y_En = 0;
    stStatus.bMotor_z_En = 0;

    nHashCompare = stMessage.nHashCompare;
}

/*-------------------------------------------------------------------------------------------------
    Destructor -- Default
*/
CU_Message::~CU_Message()
{

}

// UUC_Message -- Public Functions  ////////////////////////////////////////////////////////////////

/*-------------------------------------------------------------------------------------------------
    Constructor -- Default
*/
UUC_Message::UUC_Message()
{
    nSequenceNum = nHashCompare = 0;

    stStatus.bOperating = 0;
    stStatus.bTaskInProgress = 0;
    stStatus.bTaskComplete = 0;

    fPosition_x_cmd = fPosition_y_cmd = fPosition_z_cmd = 0;
    fVelocity_x_cmd = fVelocity_y_cmd = fVelocity_z_cmd = 0;
    fPosition_x = fPosition_y = fPosition_z = 0;
    fVelocity_x = fVelocity_y = fVelocity_z = 0;
}

/*-------------------------------------------------------------------------------------------------
	Constructor -- Accepts UUC_Message_Structure_Normal_T structure
*/
UUC_Message::UUC_Message(UUC_Message_Structure_Normal_T & stMessage)
{
	nSequenceNum = stMessage.nSequenceNum;

	stStatus.bOperating = stMessage.stStatus.bOperating;
	stStatus.bTaskInProgress = stMessage.stStatus.bTaskInProgress;
	stStatus.bTaskComplete = stMessage.stStatus.bTaskComplete;

	fPosition_x_cmd = stMessage.fPosition_x_cmd;
	fPosition_y_cmd = stMessage.fPosition_y_cmd;
	fPosition_z_cmd = stMessage.fPosition_z_cmd;
	fVelocity_x_cmd = stMessage.fVelocity_x_cmd;
	fVelocity_y_cmd = stMessage.fVelocity_y_cmd;
	fVelocity_z_cmd = stMessage.fVelocity_z_cmd;
	fPosition_x = stMessage.fPosition_x;
	fPosition_y = stMessage.fPosition_y;
	fPosition_z = stMessage.fPosition_z;
	fVelocity_x = stMessage.fVelocity_x;
	fVelocity_y = stMessage.fVelocity_y;
	fVelocity_z = stMessage.fVelocity_z;
}

/*-------------------------------------------------------------------------------------------------
	Constructor -- Accepts UUC_Message_Structure_Recovery_T structure
*/
UUC_Message::UUC_Message(UUC_Message_Structure_Recovery_T & stMessage)
{
	nSequenceNum = stMessage.nSequenceNum;

	stStatus.bOperating = stMessage.stStatus.bOperating;
	stStatus.bTaskInProgress = stMessage.stStatus.bTaskInProgress;
	stStatus.bTaskComplete = stMessage.stStatus.bTaskComplete;

	fPosition_x = stMessage.fPosition_x;
	fPosition_y = stMessage.fPosition_y;
	fPosition_z = stMessage.fPosition_z;
	fVelocity_x = stMessage.fVelocity_x;
	fVelocity_y = stMessage.fVelocity_y;
	fVelocity_z = stMessage.fVelocity_z;

	nHashCompare = stMessage.nHashCompare;
}

/*-------------------------------------------------------------------------------------------------
    Destructor -- Default
*/
UUC_Message::~UUC_Message()
{

}