#ifndef __BFS_H__
#define __BFS_H__

#include "AdjMatrixUndirGraph.h"		// ����ͼ�ڽӾ���
#include "LinkQueue.h"					// ������


// ͼ�Ĺ������(breadth firsts)����
template <class ElemType>
void BFSTraverse(const AdjMatrixUndirGraph<ElemType> &g, void (*Visit)(const ElemType &))
{
	int v;
	for (v = 0; v < g.GetVexNum(); v++)
		g.SetTag(v, UNVISITED); // ��ÿ��������δ���ʱ�־

	for (v = 0; v < g.GetVexNum(); v++)
		if (g.GetTag(v) == UNVISITED) 
			BFS(g, v , Visit); 	// ����δ���ʵĶ���v��ʼ���й����������
}



// ͼ�Ĺ����������(breadth first search)
template <class ElemType>
void BFS(const AdjMatrixUndirGraph<ElemType> &g, int v, void (*Visit)(const ElemType &))
{	
	// ����������Ӷ���v�������й����������
	LinkQueue<int> q;
    int u, w;
    ElemType e;
    g.SetTag(v, VISITED);						// �����ʱ�־
	g.GetElem(v, e);							// ȡ����v������Ԫ��ֵ 
	Visit(e);									// ���ʶ���v
	q.EnQueue(v);	                            // ����v��� 
	while (!q.IsEmpty())	{	
	   q.DelQueue(u);
	   for (w = g.FirstAdjVex(u); w != -1; w = g.NextAdjVex(u, w))
			if (g.GetTag(w) == UNVISITED){ // ��u��δ���ʹ����ڽӶ���w���з���
                g.SetTag(w, VISITED);	
	            g.GetElem(w, e);	
	            Visit(e);	
				q.EnQueue(w);
            }	
	}
}

#endif
