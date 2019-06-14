#include "Generic.h"

namespace interpreter {

	////////////////////////////////////////////////////////////////////////////////
	// ������� ��������
	////////////////////////////////////////////////////////////////////////////////

	//------------------------------------------------------------------------------
	// NOP - ����� ��������� eip �� ��������� ����������
	void nop (CVMState& vmState)
	{
		// Execute nothing
		{
		}
	}

	//------------------------------------------------------------------------------
	// ����������, ���������������� ���������� �������
	// BRK
	void brk (CVMState& vmState)
	{
		// Execute
		{
			// TODO
		}
	}

	//------------------------------------------------------------------------------
	// ��������� ��������� ������ ��������������
	void halt (CVMState& vmState)
	{
		vmState.m_bStillWorking = 0;
	}

	//------------------------------------------------------------------------------
}