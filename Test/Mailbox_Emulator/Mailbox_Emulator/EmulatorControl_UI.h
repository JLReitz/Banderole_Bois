#pragma once

namespace MailboxEmulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EmulatorControl_UI
	/// </summary>
	public ref class EmulatorControl_UI : public System::Windows::Forms::Form
	{
	public:
		EmulatorControl_UI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EmulatorControl_UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  CUOperationEn_GroupBox;
	protected:

	private: System::Windows::Forms::RadioButton^  CUOperation_Den_Radio;
	protected:


	private: System::Windows::Forms::RadioButton^  CUOperation_En_Radio;
	private: System::Windows::Forms::GroupBox^  CUCommands_GroupBox;


	private: System::Windows::Forms::CheckBox^  CUMotorZ_En_Check;

	private: System::Windows::Forms::CheckBox^  CUMotorY_En_Check;

	private: System::Windows::Forms::CheckBox^  CUMotorX_En_Check;


	private: System::Windows::Forms::Label^  CUVelocityCmd_Label;
	private: System::Windows::Forms::Label^  CUTorqueCmd_Label;


	private: System::Windows::Forms::TextBox^  CUVelocityZCmd_Textbox;

	private: System::Windows::Forms::TextBox^  CUPositionZCmd_Textbox;



	private: System::Windows::Forms::TextBox^  CUVelocityYCmd_Textbox;

	private: System::Windows::Forms::TextBox^  CUPositionYCmd_Textbox;



	private: System::Windows::Forms::TextBox^  CUVelocityXCmd_Textbox;

	private: System::Windows::Forms::TextBox^  CUPositionXCmd_Textbox;


	private: System::Windows::Forms::Label^  CUAxisZCmd_Label;
	private: System::Windows::Forms::Label^  CUAxisYCmd_Label;
	private: System::Windows::Forms::Label^  CUAxisXCmd_Label;
	private: System::Windows::Forms::GroupBox^  CUStSN_Groupbox;

	private: System::Windows::Forms::RadioButton^  CUStatus_eNormal_Radio;

	private: System::Windows::Forms::RadioButton^  CUStatus_eStart_Radio;
	private: System::Windows::Forms::CheckBox^  CUStatus_LocEn_Check;



	private: System::Windows::Forms::RadioButton^  CUStatus_eRecoveryLoc_Radio;

	private: System::Windows::Forms::RadioButton^  CUStatus_eRecovery_Radio;

	private: System::Windows::Forms::RadioButton^  CUStatus_eLoc3_Radio;

	private: System::Windows::Forms::RadioButton^  CUStatus_eLoc2_Radio;

	private: System::Windows::Forms::RadioButton^  CUStatus_eLoc1_Radio;
	private: System::Windows::Forms::Label^  CUMailboxStatus_Label;


	private: System::Windows::Forms::TextBox^  CUSequenceNum_Textbox;
	private: System::Windows::Forms::Label^  CUSequenceNum_Label;
	private: System::Windows::Forms::GroupBox^  CUMessage_Groupbox;
	private: System::Windows::Forms::GroupBox^  UUCMessage_GroupBox;
	private: System::Windows::Forms::TextBox^  CUCRC_Textbox;
	private: System::Windows::Forms::Label^  CUCRC_Label;
	private: System::Windows::Forms::GroupBox^  UUCMotionReport_Groupbox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::Label^  CUHashCompare_Label;
private: System::Windows::Forms::Label^  UUCStatusBits_Label;
private: System::Windows::Forms::CheckBox^  UCTaskComplete_Check;
private: System::Windows::Forms::CheckBox^  UCTaskinProgress_Check;
private: System::Windows::Forms::CheckBox^  UUCOperating_Check;






	protected:

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->CUOperationEn_GroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->CUMotorZ_En_Check = (gcnew System::Windows::Forms::CheckBox());
			this->CUMotorY_En_Check = (gcnew System::Windows::Forms::CheckBox());
			this->CUMotorX_En_Check = (gcnew System::Windows::Forms::CheckBox());
			this->CUOperation_Den_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUOperation_En_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUCommands_GroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->CUVelocityCmd_Label = (gcnew System::Windows::Forms::Label());
			this->CUTorqueCmd_Label = (gcnew System::Windows::Forms::Label());
			this->CUVelocityZCmd_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->CUPositionZCmd_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->CUVelocityYCmd_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->CUPositionYCmd_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->CUVelocityXCmd_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->CUPositionXCmd_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->CUAxisZCmd_Label = (gcnew System::Windows::Forms::Label());
			this->CUAxisYCmd_Label = (gcnew System::Windows::Forms::Label());
			this->CUAxisXCmd_Label = (gcnew System::Windows::Forms::Label());
			this->CUStSN_Groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->CUSequenceNum_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->CUSequenceNum_Label = (gcnew System::Windows::Forms::Label());
			this->CUStatus_LocEn_Check = (gcnew System::Windows::Forms::CheckBox());
			this->CUStatus_eRecoveryLoc_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUStatus_eRecovery_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUStatus_eLoc3_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUStatus_eLoc2_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUStatus_eLoc1_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUMailboxStatus_Label = (gcnew System::Windows::Forms::Label());
			this->CUStatus_eNormal_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUStatus_eStart_Radio = (gcnew System::Windows::Forms::RadioButton());
			this->CUMessage_Groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->UUCMessage_GroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->UUCMotionReport_Groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->CUCRC_Label = (gcnew System::Windows::Forms::Label());
			this->CUCRC_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->CUHashCompare_Label = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->UUCOperating_Check = (gcnew System::Windows::Forms::CheckBox());
			this->UCTaskinProgress_Check = (gcnew System::Windows::Forms::CheckBox());
			this->UCTaskComplete_Check = (gcnew System::Windows::Forms::CheckBox());
			this->UUCStatusBits_Label = (gcnew System::Windows::Forms::Label());
			this->CUOperationEn_GroupBox->SuspendLayout();
			this->CUCommands_GroupBox->SuspendLayout();
			this->CUStSN_Groupbox->SuspendLayout();
			this->CUMessage_Groupbox->SuspendLayout();
			this->UUCMessage_GroupBox->SuspendLayout();
			this->UUCMotionReport_Groupbox->SuspendLayout();
			this->SuspendLayout();
			// 
			// CUOperationEn_GroupBox
			// 
			this->CUOperationEn_GroupBox->Controls->Add(this->CUMotorZ_En_Check);
			this->CUOperationEn_GroupBox->Controls->Add(this->CUMotorY_En_Check);
			this->CUOperationEn_GroupBox->Controls->Add(this->CUMotorX_En_Check);
			this->CUOperationEn_GroupBox->Controls->Add(this->CUOperation_Den_Radio);
			this->CUOperationEn_GroupBox->Controls->Add(this->CUOperation_En_Radio);
			this->CUOperationEn_GroupBox->Location = System::Drawing::Point(9, 20);
			this->CUOperationEn_GroupBox->Name = L"CUOperationEn_GroupBox";
			this->CUOperationEn_GroupBox->Size = System::Drawing::Size(237, 60);
			this->CUOperationEn_GroupBox->TabIndex = 0;
			this->CUOperationEn_GroupBox->TabStop = false;
			this->CUOperationEn_GroupBox->Text = L"Operation Enable";
			// 
			// CUMotorZ_En_Check
			// 
			this->CUMotorZ_En_Check->AutoSize = true;
			this->CUMotorZ_En_Check->Location = System::Drawing::Point(110, 40);
			this->CUMotorZ_En_Check->Name = L"CUMotorZ_En_Check";
			this->CUMotorZ_En_Check->Size = System::Drawing::Size(99, 17);
			this->CUMotorZ_En_Check->TabIndex = 4;
			this->CUMotorZ_En_Check->TabStop = false;
			this->CUMotorZ_En_Check->Text = L"Motor Z Enable";
			this->CUMotorZ_En_Check->UseVisualStyleBackColor = true;
			// 
			// CUMotorY_En_Check
			// 
			this->CUMotorY_En_Check->AutoSize = true;
			this->CUMotorY_En_Check->Location = System::Drawing::Point(110, 25);
			this->CUMotorY_En_Check->Name = L"CUMotorY_En_Check";
			this->CUMotorY_En_Check->Size = System::Drawing::Size(99, 17);
			this->CUMotorY_En_Check->TabIndex = 3;
			this->CUMotorY_En_Check->TabStop = false;
			this->CUMotorY_En_Check->Text = L"Motor Y Enable";
			this->CUMotorY_En_Check->UseVisualStyleBackColor = true;
			// 
			// CUMotorX_En_Check
			// 
			this->CUMotorX_En_Check->AutoSize = true;
			this->CUMotorX_En_Check->Location = System::Drawing::Point(110, 10);
			this->CUMotorX_En_Check->Name = L"CUMotorX_En_Check";
			this->CUMotorX_En_Check->Size = System::Drawing::Size(99, 17);
			this->CUMotorX_En_Check->TabIndex = 2;
			this->CUMotorX_En_Check->TabStop = false;
			this->CUMotorX_En_Check->Text = L"Motor X Enable";
			this->CUMotorX_En_Check->UseVisualStyleBackColor = true;
			this->CUMotorX_En_Check->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::MotorX_En_Check_CheckedChanged);
			// 
			// CUOperation_Den_Radio
			// 
			this->CUOperation_Den_Radio->AutoSize = true;
			this->CUOperation_Den_Radio->Checked = true;
			this->CUOperation_Den_Radio->Location = System::Drawing::Point(7, 36);
			this->CUOperation_Den_Radio->Name = L"CUOperation_Den_Radio";
			this->CUOperation_Den_Radio->Size = System::Drawing::Size(60, 17);
			this->CUOperation_Den_Radio->TabIndex = 1;
			this->CUOperation_Den_Radio->TabStop = true;
			this->CUOperation_Den_Radio->Text = L"Disable";
			this->CUOperation_Den_Radio->UseVisualStyleBackColor = true;
			this->CUOperation_Den_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Operation_Den_Radio_CheckedChanged);
			// 
			// CUOperation_En_Radio
			// 
			this->CUOperation_En_Radio->AutoSize = true;
			this->CUOperation_En_Radio->Location = System::Drawing::Point(7, 20);
			this->CUOperation_En_Radio->Name = L"CUOperation_En_Radio";
			this->CUOperation_En_Radio->Size = System::Drawing::Size(58, 17);
			this->CUOperation_En_Radio->TabIndex = 0;
			this->CUOperation_En_Radio->Text = L"Enable";
			this->CUOperation_En_Radio->UseVisualStyleBackColor = true;
			this->CUOperation_En_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Operation_En_Radio_CheckedChanged);
			// 
			// CUCommands_GroupBox
			// 
			this->CUCommands_GroupBox->Controls->Add(this->CUVelocityCmd_Label);
			this->CUCommands_GroupBox->Controls->Add(this->CUOperationEn_GroupBox);
			this->CUCommands_GroupBox->Controls->Add(this->CUTorqueCmd_Label);
			this->CUCommands_GroupBox->Controls->Add(this->CUVelocityZCmd_Textbox);
			this->CUCommands_GroupBox->Controls->Add(this->CUPositionZCmd_Textbox);
			this->CUCommands_GroupBox->Controls->Add(this->CUVelocityYCmd_Textbox);
			this->CUCommands_GroupBox->Controls->Add(this->CUPositionYCmd_Textbox);
			this->CUCommands_GroupBox->Controls->Add(this->CUVelocityXCmd_Textbox);
			this->CUCommands_GroupBox->Controls->Add(this->CUPositionXCmd_Textbox);
			this->CUCommands_GroupBox->Controls->Add(this->CUAxisZCmd_Label);
			this->CUCommands_GroupBox->Controls->Add(this->CUAxisYCmd_Label);
			this->CUCommands_GroupBox->Controls->Add(this->CUAxisXCmd_Label);
			this->CUCommands_GroupBox->Location = System::Drawing::Point(5, 19);
			this->CUCommands_GroupBox->Name = L"CUCommands_GroupBox";
			this->CUCommands_GroupBox->Size = System::Drawing::Size(259, 151);
			this->CUCommands_GroupBox->TabIndex = 1;
			this->CUCommands_GroupBox->TabStop = false;
			this->CUCommands_GroupBox->Text = L"Commands";
			// 
			// CUVelocityCmd_Label
			// 
			this->CUVelocityCmd_Label->AutoSize = true;
			this->CUVelocityCmd_Label->Location = System::Drawing::Point(6, 124);
			this->CUVelocityCmd_Label->Name = L"CUVelocityCmd_Label";
			this->CUVelocityCmd_Label->Size = System::Drawing::Size(70, 13);
			this->CUVelocityCmd_Label->TabIndex = 13;
			this->CUVelocityCmd_Label->Text = L"Velocity (rpm)";
			// 
			// CUTorqueCmd_Label
			// 
			this->CUTorqueCmd_Label->AutoSize = true;
			this->CUTorqueCmd_Label->Location = System::Drawing::Point(6, 102);
			this->CUTorqueCmd_Label->Name = L"CUTorqueCmd_Label";
			this->CUTorqueCmd_Label->Size = System::Drawing::Size(71, 13);
			this->CUTorqueCmd_Label->TabIndex = 12;
			this->CUTorqueCmd_Label->Text = L"Position (deg)";
			// 
			// CUVelocityZCmd_Textbox
			// 
			this->CUVelocityZCmd_Textbox->Location = System::Drawing::Point(196, 121);
			this->CUVelocityZCmd_Textbox->Name = L"CUVelocityZCmd_Textbox";
			this->CUVelocityZCmd_Textbox->Size = System::Drawing::Size(50, 20);
			this->CUVelocityZCmd_Textbox->TabIndex = 10;
			this->CUVelocityZCmd_Textbox->Text = L"0";
			this->CUVelocityZCmd_Textbox->TextChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::VelocityZCmd_Textbox_TextChanged);
			// 
			// CUPositionZCmd_Textbox
			// 
			this->CUPositionZCmd_Textbox->Location = System::Drawing::Point(196, 99);
			this->CUPositionZCmd_Textbox->Name = L"CUPositionZCmd_Textbox";
			this->CUPositionZCmd_Textbox->Size = System::Drawing::Size(50, 20);
			this->CUPositionZCmd_Textbox->TabIndex = 9;
			this->CUPositionZCmd_Textbox->Text = L"0";
			this->CUPositionZCmd_Textbox->TextChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::PositionZCmd_Textbox_TextChanged);
			// 
			// CUVelocityYCmd_Textbox
			// 
			this->CUVelocityYCmd_Textbox->Location = System::Drawing::Point(140, 121);
			this->CUVelocityYCmd_Textbox->Name = L"CUVelocityYCmd_Textbox";
			this->CUVelocityYCmd_Textbox->Size = System::Drawing::Size(50, 20);
			this->CUVelocityYCmd_Textbox->TabIndex = 7;
			this->CUVelocityYCmd_Textbox->Text = L"0";
			this->CUVelocityYCmd_Textbox->TextChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::VelocityYCmd_Textbox_TextChanged);
			// 
			// CUPositionYCmd_Textbox
			// 
			this->CUPositionYCmd_Textbox->Location = System::Drawing::Point(140, 99);
			this->CUPositionYCmd_Textbox->Name = L"CUPositionYCmd_Textbox";
			this->CUPositionYCmd_Textbox->Size = System::Drawing::Size(50, 20);
			this->CUPositionYCmd_Textbox->TabIndex = 6;
			this->CUPositionYCmd_Textbox->Text = L"0";
			this->CUPositionYCmd_Textbox->TextChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::PositionYCmd_Textbox_TextChanged);
			// 
			// CUVelocityXCmd_Textbox
			// 
			this->CUVelocityXCmd_Textbox->Location = System::Drawing::Point(84, 121);
			this->CUVelocityXCmd_Textbox->Name = L"CUVelocityXCmd_Textbox";
			this->CUVelocityXCmd_Textbox->Size = System::Drawing::Size(50, 20);
			this->CUVelocityXCmd_Textbox->TabIndex = 4;
			this->CUVelocityXCmd_Textbox->Text = L"0";
			this->CUVelocityXCmd_Textbox->TextChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::VelocityXCmd_Textbox_TextChanged);
			// 
			// CUPositionXCmd_Textbox
			// 
			this->CUPositionXCmd_Textbox->Location = System::Drawing::Point(84, 99);
			this->CUPositionXCmd_Textbox->Name = L"CUPositionXCmd_Textbox";
			this->CUPositionXCmd_Textbox->Size = System::Drawing::Size(50, 20);
			this->CUPositionXCmd_Textbox->TabIndex = 3;
			this->CUPositionXCmd_Textbox->Text = L"0";
			this->CUPositionXCmd_Textbox->TextChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::PositionXCmd_Textbox_TextChanged);
			// 
			// CUAxisZCmd_Label
			// 
			this->CUAxisZCmd_Label->AutoSize = true;
			this->CUAxisZCmd_Label->Location = System::Drawing::Point(201, 83);
			this->CUAxisZCmd_Label->Name = L"CUAxisZCmd_Label";
			this->CUAxisZCmd_Label->Size = System::Drawing::Size(39, 13);
			this->CUAxisZCmd_Label->TabIndex = 2;
			this->CUAxisZCmd_Label->Text = L"Z Axis:";
			// 
			// CUAxisYCmd_Label
			// 
			this->CUAxisYCmd_Label->AutoSize = true;
			this->CUAxisYCmd_Label->Location = System::Drawing::Point(145, 83);
			this->CUAxisYCmd_Label->Name = L"CUAxisYCmd_Label";
			this->CUAxisYCmd_Label->Size = System::Drawing::Size(39, 13);
			this->CUAxisYCmd_Label->TabIndex = 1;
			this->CUAxisYCmd_Label->Text = L"Y Axis:";
			// 
			// CUAxisXCmd_Label
			// 
			this->CUAxisXCmd_Label->AutoSize = true;
			this->CUAxisXCmd_Label->Location = System::Drawing::Point(89, 83);
			this->CUAxisXCmd_Label->Name = L"CUAxisXCmd_Label";
			this->CUAxisXCmd_Label->Size = System::Drawing::Size(39, 13);
			this->CUAxisXCmd_Label->TabIndex = 0;
			this->CUAxisXCmd_Label->Text = L"X Axis:";
			// 
			// CUStSN_Groupbox
			// 
			this->CUStSN_Groupbox->Controls->Add(this->CUSequenceNum_Textbox);
			this->CUStSN_Groupbox->Controls->Add(this->CUSequenceNum_Label);
			this->CUStSN_Groupbox->Controls->Add(this->CUStatus_LocEn_Check);
			this->CUStSN_Groupbox->Controls->Add(this->CUStatus_eRecoveryLoc_Radio);
			this->CUStSN_Groupbox->Controls->Add(this->CUStatus_eRecovery_Radio);
			this->CUStSN_Groupbox->Controls->Add(this->CUStatus_eLoc3_Radio);
			this->CUStSN_Groupbox->Controls->Add(this->CUStatus_eLoc2_Radio);
			this->CUStSN_Groupbox->Controls->Add(this->CUStatus_eLoc1_Radio);
			this->CUStSN_Groupbox->Controls->Add(this->CUMailboxStatus_Label);
			this->CUStSN_Groupbox->Controls->Add(this->CUStatus_eNormal_Radio);
			this->CUStSN_Groupbox->Controls->Add(this->CUStatus_eStart_Radio);
			this->CUStSN_Groupbox->Location = System::Drawing::Point(5, 176);
			this->CUStSN_Groupbox->Name = L"CUStSN_Groupbox";
			this->CUStSN_Groupbox->Size = System::Drawing::Size(259, 209);
			this->CUStSN_Groupbox->TabIndex = 2;
			this->CUStSN_Groupbox->TabStop = false;
			this->CUStSN_Groupbox->Text = L"Status and Sequence Number";
			// 
			// CUSequenceNum_Textbox
			// 
			this->CUSequenceNum_Textbox->Location = System::Drawing::Point(16, 43);
			this->CUSequenceNum_Textbox->Name = L"CUSequenceNum_Textbox";
			this->CUSequenceNum_Textbox->ReadOnly = true;
			this->CUSequenceNum_Textbox->Size = System::Drawing::Size(100, 20);
			this->CUSequenceNum_Textbox->TabIndex = 10;
			// 
			// CUSequenceNum_Label
			// 
			this->CUSequenceNum_Label->AutoSize = true;
			this->CUSequenceNum_Label->Location = System::Drawing::Point(7, 27);
			this->CUSequenceNum_Label->Name = L"CUSequenceNum_Label";
			this->CUSequenceNum_Label->Size = System::Drawing::Size(84, 13);
			this->CUSequenceNum_Label->TabIndex = 9;
			this->CUSequenceNum_Label->Text = L"Sequence Num:";
			// 
			// CUStatus_LocEn_Check
			// 
			this->CUStatus_LocEn_Check->AutoSize = true;
			this->CUStatus_LocEn_Check->Location = System::Drawing::Point(174, 89);
			this->CUStatus_LocEn_Check->Name = L"CUStatus_LocEn_Check";
			this->CUStatus_LocEn_Check->Size = System::Drawing::Size(66, 17);
			this->CUStatus_LocEn_Check->TabIndex = 8;
			this->CUStatus_LocEn_Check->Text = L"Set LOC";
			this->CUStatus_LocEn_Check->UseVisualStyleBackColor = true;
			this->CUStatus_LocEn_Check->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Status_LocEn_Check_CheckedChanged);
			// 
			// CUStatus_eRecoveryLoc_Radio
			// 
			this->CUStatus_eRecoveryLoc_Radio->AutoSize = true;
			this->CUStatus_eRecoveryLoc_Radio->Location = System::Drawing::Point(16, 185);
			this->CUStatus_eRecoveryLoc_Radio->Name = L"CUStatus_eRecoveryLoc_Radio";
			this->CUStatus_eRecoveryLoc_Radio->Size = System::Drawing::Size(136, 17);
			this->CUStatus_eRecoveryLoc_Radio->TabIndex = 7;
			this->CUStatus_eRecoveryLoc_Radio->Text = L"eRecovery_LOC (0x19)";
			this->CUStatus_eRecoveryLoc_Radio->UseVisualStyleBackColor = true;
			this->CUStatus_eRecoveryLoc_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Status_eRecoveryLoc_Radio_CheckedChanged);
			// 
			// CUStatus_eRecovery_Radio
			// 
			this->CUStatus_eRecovery_Radio->AutoSize = true;
			this->CUStatus_eRecovery_Radio->Location = System::Drawing::Point(16, 169);
			this->CUStatus_eRecovery_Radio->Name = L"CUStatus_eRecovery_Radio";
			this->CUStatus_eRecovery_Radio->Size = System::Drawing::Size(109, 17);
			this->CUStatus_eRecovery_Radio->TabIndex = 6;
			this->CUStatus_eRecovery_Radio->Text = L"eRecovery (0x18)";
			this->CUStatus_eRecovery_Radio->UseVisualStyleBackColor = true;
			this->CUStatus_eRecovery_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Status_eRecovery_Radio_CheckedChanged);
			// 
			// CUStatus_eLoc3_Radio
			// 
			this->CUStatus_eLoc3_Radio->AutoSize = true;
			this->CUStatus_eLoc3_Radio->Location = System::Drawing::Point(16, 153);
			this->CUStatus_eLoc3_Radio->Name = L"CUStatus_eLoc3_Radio";
			this->CUStatus_eLoc3_Radio->Size = System::Drawing::Size(96, 17);
			this->CUStatus_eLoc3_Radio->TabIndex = 5;
			this->CUStatus_eLoc3_Radio->Text = L"eLOC_3 (0x13)";
			this->CUStatus_eLoc3_Radio->UseVisualStyleBackColor = true;
			this->CUStatus_eLoc3_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Status_eLoc3_Radio_CheckedChanged);
			// 
			// CUStatus_eLoc2_Radio
			// 
			this->CUStatus_eLoc2_Radio->AutoSize = true;
			this->CUStatus_eLoc2_Radio->Location = System::Drawing::Point(16, 137);
			this->CUStatus_eLoc2_Radio->Name = L"CUStatus_eLoc2_Radio";
			this->CUStatus_eLoc2_Radio->Size = System::Drawing::Size(96, 17);
			this->CUStatus_eLoc2_Radio->TabIndex = 4;
			this->CUStatus_eLoc2_Radio->Text = L"eLOC_2 (0x12)";
			this->CUStatus_eLoc2_Radio->UseVisualStyleBackColor = true;
			this->CUStatus_eLoc2_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Status_eLoc2_Radio_CheckedChanged);
			// 
			// CUStatus_eLoc1_Radio
			// 
			this->CUStatus_eLoc1_Radio->AutoSize = true;
			this->CUStatus_eLoc1_Radio->Location = System::Drawing::Point(16, 121);
			this->CUStatus_eLoc1_Radio->Name = L"CUStatus_eLoc1_Radio";
			this->CUStatus_eLoc1_Radio->Size = System::Drawing::Size(96, 17);
			this->CUStatus_eLoc1_Radio->TabIndex = 3;
			this->CUStatus_eLoc1_Radio->Text = L"eLOC_1 (0x11)";
			this->CUStatus_eLoc1_Radio->UseVisualStyleBackColor = true;
			this->CUStatus_eLoc1_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Status_eLoc1_Radio_CheckedChanged);
			// 
			// CUMailboxStatus_Label
			// 
			this->CUMailboxStatus_Label->AutoSize = true;
			this->CUMailboxStatus_Label->Location = System::Drawing::Point(7, 73);
			this->CUMailboxStatus_Label->Name = L"CUMailboxStatus_Label";
			this->CUMailboxStatus_Label->Size = System::Drawing::Size(79, 13);
			this->CUMailboxStatus_Label->TabIndex = 2;
			this->CUMailboxStatus_Label->Text = L"Mailbox Status:";
			// 
			// CUStatus_eNormal_Radio
			// 
			this->CUStatus_eNormal_Radio->AutoSize = true;
			this->CUStatus_eNormal_Radio->Location = System::Drawing::Point(16, 105);
			this->CUStatus_eNormal_Radio->Name = L"CUStatus_eNormal_Radio";
			this->CUStatus_eNormal_Radio->Size = System::Drawing::Size(96, 17);
			this->CUStatus_eNormal_Radio->TabIndex = 1;
			this->CUStatus_eNormal_Radio->Text = L"eNormal (0x10)";
			this->CUStatus_eNormal_Radio->UseVisualStyleBackColor = true;
			this->CUStatus_eNormal_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Status_eNormal_Radio_CheckedChanged);
			// 
			// CUStatus_eStart_Radio
			// 
			this->CUStatus_eStart_Radio->AutoSize = true;
			this->CUStatus_eStart_Radio->Location = System::Drawing::Point(16, 89);
			this->CUStatus_eStart_Radio->Name = L"CUStatus_eStart_Radio";
			this->CUStatus_eStart_Radio->Size = System::Drawing::Size(87, 17);
			this->CUStatus_eStart_Radio->TabIndex = 0;
			this->CUStatus_eStart_Radio->Text = L"eStart (0xAA)";
			this->CUStatus_eStart_Radio->UseVisualStyleBackColor = true;
			this->CUStatus_eStart_Radio->CheckedChanged += gcnew System::EventHandler(this, &EmulatorControl_UI::Status_eStart_Radio_CheckedChanged);
			// 
			// CUMessage_Groupbox
			// 
			this->CUMessage_Groupbox->BackColor = System::Drawing::SystemColors::Control;
			this->CUMessage_Groupbox->Controls->Add(this->textBox7);
			this->CUMessage_Groupbox->Controls->Add(this->CUHashCompare_Label);
			this->CUMessage_Groupbox->Controls->Add(this->CUCRC_Textbox);
			this->CUMessage_Groupbox->Controls->Add(this->CUCRC_Label);
			this->CUMessage_Groupbox->Controls->Add(this->CUStSN_Groupbox);
			this->CUMessage_Groupbox->Controls->Add(this->CUCommands_GroupBox);
			this->CUMessage_Groupbox->Location = System::Drawing::Point(7, 7);
			this->CUMessage_Groupbox->Name = L"CUMessage_Groupbox";
			this->CUMessage_Groupbox->Size = System::Drawing::Size(272, 423);
			this->CUMessage_Groupbox->TabIndex = 3;
			this->CUMessage_Groupbox->TabStop = false;
			this->CUMessage_Groupbox->Text = L"CU Message";
			// 
			// UUCMessage_GroupBox
			// 
			this->UUCMessage_GroupBox->Controls->Add(this->UUCMotionReport_Groupbox);
			this->UUCMessage_GroupBox->Location = System::Drawing::Point(298, 7);
			this->UUCMessage_GroupBox->Name = L"UUCMessage_GroupBox";
			this->UUCMessage_GroupBox->Size = System::Drawing::Size(492, 392);
			this->UUCMessage_GroupBox->TabIndex = 4;
			this->UUCMessage_GroupBox->TabStop = false;
			this->UUCMessage_GroupBox->Text = L"UUC Message";
			// 
			// UUCMotionReport_Groupbox
			// 
			this->UUCMotionReport_Groupbox->Controls->Add(this->UUCStatusBits_Label);
			this->UUCMotionReport_Groupbox->Controls->Add(this->UCTaskComplete_Check);
			this->UUCMotionReport_Groupbox->Controls->Add(this->UCTaskinProgress_Check);
			this->UUCMotionReport_Groupbox->Controls->Add(this->UUCOperating_Check);
			this->UUCMotionReport_Groupbox->Controls->Add(this->label1);
			this->UUCMotionReport_Groupbox->Controls->Add(this->label5);
			this->UUCMotionReport_Groupbox->Controls->Add(this->label2);
			this->UUCMotionReport_Groupbox->Controls->Add(this->label4);
			this->UUCMotionReport_Groupbox->Controls->Add(this->textBox1);
			this->UUCMotionReport_Groupbox->Controls->Add(this->label3);
			this->UUCMotionReport_Groupbox->Controls->Add(this->textBox2);
			this->UUCMotionReport_Groupbox->Controls->Add(this->textBox6);
			this->UUCMotionReport_Groupbox->Controls->Add(this->textBox3);
			this->UUCMotionReport_Groupbox->Controls->Add(this->textBox5);
			this->UUCMotionReport_Groupbox->Controls->Add(this->textBox4);
			this->UUCMotionReport_Groupbox->Location = System::Drawing::Point(6, 19);
			this->UUCMotionReport_Groupbox->Name = L"UUCMotionReport_Groupbox";
			this->UUCMotionReport_Groupbox->Size = System::Drawing::Size(479, 80);
			this->UUCMotionReport_Groupbox->TabIndex = 0;
			this->UUCMotionReport_Groupbox->TabStop = false;
			this->UUCMotionReport_Groupbox->Text = L"Motion Report";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Velocity (rpm)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Position (deg)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(198, 54);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(50, 20);
			this->textBox1->TabIndex = 22;
			this->textBox1->Text = L"0";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(198, 32);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(50, 20);
			this->textBox2->TabIndex = 21;
			this->textBox2->Text = L"0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(142, 54);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(50, 20);
			this->textBox3->TabIndex = 20;
			this->textBox3->Text = L"0";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(142, 32);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(50, 20);
			this->textBox4->TabIndex = 19;
			this->textBox4->Text = L"0";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(86, 54);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(50, 20);
			this->textBox5->TabIndex = 18;
			this->textBox5->Text = L"0";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(86, 32);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(50, 20);
			this->textBox6->TabIndex = 17;
			this->textBox6->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(203, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Z Axis:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(147, 16);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Y Axis:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(91, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"X Axis:";
			// 
			// CUCRC_Label
			// 
			this->CUCRC_Label->AutoSize = true;
			this->CUCRC_Label->Location = System::Drawing::Point(6, 395);
			this->CUCRC_Label->Name = L"CUCRC_Label";
			this->CUCRC_Label->Size = System::Drawing::Size(32, 13);
			this->CUCRC_Label->TabIndex = 3;
			this->CUCRC_Label->Text = L"CRC:";
			// 
			// CUCRC_Textbox
			// 
			this->CUCRC_Textbox->Location = System::Drawing::Point(41, 392);
			this->CUCRC_Textbox->Name = L"CUCRC_Textbox";
			this->CUCRC_Textbox->ReadOnly = true;
			this->CUCRC_Textbox->Size = System::Drawing::Size(50, 20);
			this->CUCRC_Textbox->TabIndex = 11;
			this->CUCRC_Textbox->Text = L"0x0000";
			// 
			// CUHashCompare_Label
			// 
			this->CUHashCompare_Label->AutoSize = true;
			this->CUHashCompare_Label->Location = System::Drawing::Point(115, 395);
			this->CUHashCompare_Label->Name = L"CUHashCompare_Label";
			this->CUHashCompare_Label->Size = System::Drawing::Size(80, 13);
			this->CUHashCompare_Label->TabIndex = 11;
			this->CUHashCompare_Label->Text = L"HashCompare: ";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(195, 392);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(50, 20);
			this->textBox7->TabIndex = 12;
			// 
			// UUCOperating_Check
			// 
			this->UUCOperating_Check->AutoSize = true;
			this->UUCOperating_Check->Location = System::Drawing::Point(280, 30);
			this->UUCOperating_Check->Name = L"UUCOperating_Check";
			this->UUCOperating_Check->Size = System::Drawing::Size(72, 17);
			this->UUCOperating_Check->TabIndex = 25;
			this->UUCOperating_Check->Text = L"Operating";
			this->UUCOperating_Check->UseVisualStyleBackColor = true;
			// 
			// UCTaskinProgress_Check
			// 
			this->UCTaskinProgress_Check->AutoSize = true;
			this->UCTaskinProgress_Check->Location = System::Drawing::Point(280, 45);
			this->UCTaskinProgress_Check->Name = L"UCTaskinProgress_Check";
			this->UCTaskinProgress_Check->Size = System::Drawing::Size(105, 17);
			this->UCTaskinProgress_Check->TabIndex = 26;
			this->UCTaskinProgress_Check->Text = L"Task in Progress";
			this->UCTaskinProgress_Check->UseVisualStyleBackColor = true;
			// 
			// UCTaskComplete_Check
			// 
			this->UCTaskComplete_Check->AutoSize = true;
			this->UCTaskComplete_Check->Location = System::Drawing::Point(280, 60);
			this->UCTaskComplete_Check->Name = L"UCTaskComplete_Check";
			this->UCTaskComplete_Check->Size = System::Drawing::Size(97, 17);
			this->UCTaskComplete_Check->TabIndex = 27;
			this->UCTaskComplete_Check->Text = L"Task Complete";
			this->UCTaskComplete_Check->UseVisualStyleBackColor = true;
			// 
			// UUCStatusBits_Label
			// 
			this->UUCStatusBits_Label->AutoSize = true;
			this->UUCStatusBits_Label->Location = System::Drawing::Point(277, 14);
			this->UUCStatusBits_Label->Name = L"UUCStatusBits_Label";
			this->UUCStatusBits_Label->Size = System::Drawing::Size(60, 13);
			this->UUCStatusBits_Label->TabIndex = 28;
			this->UUCStatusBits_Label->Text = L"Status Bits:";
			// 
			// EmulatorControl_UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 507);
			this->Controls->Add(this->UUCMessage_GroupBox);
			this->Controls->Add(this->CUMessage_Groupbox);
			this->Name = L"EmulatorControl_UI";
			this->Text = L"EmulatorControl_UI";
			this->CUOperationEn_GroupBox->ResumeLayout(false);
			this->CUOperationEn_GroupBox->PerformLayout();
			this->CUCommands_GroupBox->ResumeLayout(false);
			this->CUCommands_GroupBox->PerformLayout();
			this->CUStSN_Groupbox->ResumeLayout(false);
			this->CUStSN_Groupbox->PerformLayout();
			this->CUMessage_Groupbox->ResumeLayout(false);
			this->CUMessage_Groupbox->PerformLayout();
			this->UUCMessage_GroupBox->ResumeLayout(false);
			this->UUCMotionReport_Groupbox->ResumeLayout(false);
			this->UUCMotionReport_Groupbox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void Operation_En_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		{
		
		}

		private: System::Void Operation_Den_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{

		}

		private: System::Void MotorX_En_Check_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{

		}

		private: System::Void PositionXCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void PositionYCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void PositionZCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void VelocityXCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void VelocityYCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void VelocityZCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void TorqueXCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void TorqueYCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void TorqueZCmd_Textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void Status_eStart_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void Status_eNormal_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void Status_eLoc1_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void Status_eLoc2_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void Status_eLoc3_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void Status_eRecovery_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void Status_eRecoveryLoc_Radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		{
		}

		private: System::Void Status_LocEn_Check_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
		{
		}

};
}
