#ifndef __ADJ_LIST_NETWORK_VEX_H__
#define __ADJ_LIST_NETWORK_VEX_H__

// �ڽӱ�����������
template <class ElemType>
struct AdjListGraphVex
{
	ElemType data;						// ����Ԫ��ֵ
	AdjListGraphArc *firstarc;			// ָ���ڽ�����߽���ָ��

	AdjListGraphVex();				 
	AdjListGraphVex(ElemType val, AdjListGraphArc *adj = NULL);

};


 
template <class ElemType>
AdjListGraphVex<ElemType>::AdjListGraphVex()
// �������������һ���ն����㡪���޲ι��캯��
{
	firstarc = NULL;	
}


template <class ElemType>
AdjListGraphVex<ElemType>::AdjListGraphVex(ElemType  val, 
	AdjListGraphArc *adj)
// �����������������Ϊval,��Ϊeg�Ķ���
{
	data = val;
	firstarc = adj;
}

#endif
