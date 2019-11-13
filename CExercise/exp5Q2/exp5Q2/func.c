//
// Created by astzls on 2019-09-23.
//
#include "repo.h"
char *input(char word[], int length, FILE *src){
	char *rtv_val;
	char *find;
	rtv_val = fgets(word, length, src);
	if (rtv_val)
	{
		find = strchr(rtv_val, '\n');
		if (find){
			*find = '\0';
		}
		else{
			while (fgetc(src) != '\n')
				continue;
		}
	}
	return rtv_val;
}
MGraph createMGraph(int scale, FILE *src){
	MGraph graph = (MGraph)malloc(sizeof(struct MatrixGraph));
	graph->numberVertex = scale;
	graph->numbersEdge = 0;
	// Create a adjoining matrix.
	graph->matrix = (Weight**)malloc(scale*sizeof(Weight *));
	for (int i = 0; i<scale; i++)
		(graph->matrix)[i] = (Weight *)malloc(scale*sizeof(Weight));
	// assign every vertex to independent.
	for (int i = 0; i < scale; i++){
		for (int j = 0; j < scale; j++){
			(graph->matrix)[i][j] = 5000.0;
			if (i == j)
				(graph->matrix)[i][j] = 0.0;
		}
	}
	graph->Vertices_Info = (Spot *)malloc(sizeof(Spot)*graph->numberVertex);
	for (int i = 0; i < graph->numberVertex; i++){
		(graph->Vertices_Info)[i] = (Spot)malloc(sizeof(struct spot));
		char tmp[MAXWORD];
		puts("Spot name:");
		input(tmp, MAXWORD,src);
		strncpy((graph->Vertices_Info)[i]->name, tmp, MAXWORD);
		puts("Spot brief info(less than 100 words):");
		input(tmp, MAXWORD,src);
		strncpy((graph->Vertices_Info)[i]->brief, tmp, MAXWORD);
	}
	return graph;
}

// Insert a edge for graph used matrix to store.
void mGraphInsertEdge(MGraph graph,FILE *src,int mode){
	vertex V, W;
	Weight weight;
	while (mode==2)
	{
		puts("V, W, weight (-1 to quitted):");
		while (scanf("%d %d %lf", &V, &W, &weight) != 3 || weight >= 2500){
			puts("weight must less than 2500! Again!");
			continue;
		}
		if (V == Non_Vertex || W == Non_Vertex)
			break;
		if ((graph->matrix)[V][W] != 5000.0)
		{
			puts("Error: This edge has existed!");
			continue;
		}
		graph->numbersEdge++;
		(graph->matrix)[V][W] = weight;
		(graph->matrix)[W][V] = weight;
	}
	while (mode == 1)
	{
		fscanf(src,"%d %d %lf", &V, &W, &weight);
		if (V == Non_Vertex || W == Non_Vertex)
			break;
		if ((graph->matrix)[V][W] != 5000.0)
		{
			puts("Error: This edge has existed!");
			continue;
		}
		graph->numbersEdge++;
		(graph->matrix)[V][W] = weight;
		(graph->matrix)[W][V] = weight;
	}
}
void AllPairs(MGraph g, Weight **D, vertex **Path)
{
	int row, col;
	int step_stone;
	
	for (row = 0; row < g->numberVertex; row++){
		for (col = 0; col < g->numberVertex; col++){
			D[row][col] = g->matrix[row][col];
			if (D[row][col] == (double)0 || D[row][col] == (double)5000)
				Path[row][col] = Non_Vertex;
			else
				Path[row][col] = row;
		}
	}
	
	for (step_stone = 0; step_stone < g->numberVertex; step_stone++){
		for (row = 0; row < g->numberVertex; row++){
			for (col = 0; col < g->numberVertex; col++){
				if (D[row][step_stone] + D[step_stone][col] < D[row][col]){
					D[row][col] = D[row][step_stone] + D[step_stone][col];
					Path[row][col] = Path[step_stone][col];
				}
			}
		}
	}
}
Weight **createDistance(int scale){
	Weight **tmp = (Weight **)malloc(sizeof(Weight *)*scale);
	for (int i = 0; i < scale; i++)
		tmp[i] = (Weight *)malloc(sizeof(Weight)*scale);
	return tmp;
}
vertex **createPath(int scale){
	vertex **tmp = (vertex **)malloc(sizeof(vertex *)*scale);
	for (int i = 0; i < scale; i++)
		tmp[i] = (vertex *)malloc(sizeof(vertex)*scale);
	return tmp;
}
void printPath(vertex **Path,Weight **Dist,MGraph g){
	int i;
	Weight val;
	char name[MAXWORD];
	vertex *path = (vertex *)calloc(g->numberVertex, sizeof(vertex));
	puts("Start spot:");
	input(name, MAXWORD,stdin);
	int start=0;
	while (start<g->numberVertex && strcmp(name, g->Vertices_Info[start]->name) != 0)
		start++;
	if (start == g->numberVertex)
	{
		puts("Unknown name, please checked the name in MapJnu.");
		return;
	}
	puts("ending spot:");
	input(name, MAXWORD,stdin);
	int end = 0;
	while (end<g->numberVertex && strcmp(name, g->Vertices_Info[end]->name) != 0)
		end++;
	if (end == g->numberVertex)
	{
		puts("Unknown name, please checked the name in MapJnu.");
		return;
	}
	val = Dist[start][end];
	path[0] = end;
	for (i = 1; Path[start][end] != Non_Vertex; i++)
	{
		path[i] = Path[start][end];
		end = path[i];
	}
	printf("Minimal Path: %s", g->Vertices_Info[path[--i]]->name);
	for (int j = i - 1; j > -1; j--)
		printf(" -> %s", g->Vertices_Info[path[j]]->name);
	putchar('\n');
	printf("Total distance: %.2fm\n", val);
	free(path);
}
int settings(void){
	int judge;
	puts("*******************************");
	putchar('\n');
	puts("1. Use default settings ( Jnu )");
	puts("2.     Design it youself.      ");
	putchar('\n');
	puts("*******************************");
	while (scanf("%d", &judge) != 1 || judge > 2 || judge < 1)
		puts("Invalid input! Again~");
	getchar();
	system("cls");
	return judge;
}
void menu(vertex **Path, Weight **Dist, MGraph g, void(*func)(vertex **Path, Weight **Dist, MGraph g)){
	int judge;
	int id,spot;
	char name[MAXWORD];
	do{
		puts("***********************M E N U************************");
		putchar('\n');
		puts("1.                   Query a spot                     ");
		puts("2.    Query a shortest path from one to the other.    ");
		puts("0.                       Exit                         ");
		putchar('\n');
		puts("***********************E  N  D************************");
		while (scanf("%d", &judge) != 1 || judge > 2 || judge < 0)
			puts("Invalid input! Again~");
		getchar();
		system("cls");
		if (!judge)
			break;
		else if (judge==2)
			func(Path, Dist, g);
		else
		{
			puts("Spot name or ID :");
			input(name, MAXWORD,stdin);
			id = atoi(name);
			if (id){
				printf("%s ID: %d\n", g->Vertices_Info[id]->name, id);
				printf("%s's introduction:\n", g->Vertices_Info[id]->name);
				printf("%s\n", g->Vertices_Info[id]->brief);
				puts("Nearby spots:");
				for (int i = 0; i < g->numberVertex; i++){
					if (g->matrix[id][i] != (double)5000 && g->matrix[id][i] != (double)0)
						printf("%d : %s\n", i, g->Vertices_Info[i]->name);
				}
			}
			else{
				spot = 0;
				while (spot<g->numberVertex && strcmp(name, g->Vertices_Info[spot]->name) != 0)
					spot++;
				if (spot == g->numberVertex)
				{
					puts("Invalid name for spot!");
					continue;
				}
				printf("%s ID: %d\n", g->Vertices_Info[spot]->name, spot);
				printf("%s's introduction:\n", g->Vertices_Info[spot]->name);
				printf("%s\n", g->Vertices_Info[spot]->brief);
				puts("Nearby spots:");
				for (int i = 0; i < g->numberVertex; i++){
					if (g->matrix[spot][i] != (double)5000 && g->matrix[spot][i] != (double)0)
						printf("%d : %s\n", i, g->Vertices_Info[i]->name);
				}
			}
		}
		system("pause");
		system("cls");
	}while (judge != 0);
}

