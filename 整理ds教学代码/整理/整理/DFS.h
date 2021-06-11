#ifndef __DFS_H__
#define __DFS_H__

#include "AdjMatrixUndirGraph.h"		// 无向图邻接矩阵


// 图的深度优先(depth firsts)遍历
template <class ElemType>
void DFSTraverse(const AdjMatrixUndirGraph<ElemType> &g, void (*Visit)(const ElemType &))
{
	int v;
	for (v = 0; v < g.GetVexNum(); v++)
		g.SetTag(v, UNVISITED);// 对每个顶点设置未访问标志

	for (v = 0; v < g.GetVexNum(); v++)
		
		if (g.GetTag(v) == UNVISITED)
			DFS(g, v , Visit);// 从尚未访问的顶点v开始进行深度优先搜索 
}



// 图的深度优先搜索(depth firsts search)
template <class ElemType>
void DFS(const AdjMatrixUndirGraph<ElemType> &g, int v, void (*Visit)(const ElemType &))
{	
	ElemType e;	
	g.SetTag(v, VISITED);		// 设置顶点v已访问标志
	g.GetElem(v, e);			// 取顶点v的数据元素值 
	Visit(e);					// 访问顶点v
	for (int w = g.FirstAdjVex(v); w != -1; w = g.NextAdjVex(v, w))
		if (g.GetTag(w) == UNVISITED)
			DFS(g, w , Visit);	// 从v的尚未访问过的邻接顶点w开始进行深度优先搜索
}


#endif
