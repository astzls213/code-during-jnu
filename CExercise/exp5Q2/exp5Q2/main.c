#include "repo.h"
int main(void){
	FILE *jnuGraph;
	jnuGraph=fopen("MapJnu.txt", "r");
	if (jnuGraph == NULL)
	{
		puts("Not found file, terminated!");
		return 0;
	}
	int scale, mode;
	MGraph g;
	if ((mode=settings()) == 1){
		fscanf(jnuGraph, "%d", &scale);
		fgetc(jnuGraph);
		g = createMGraph(scale,jnuGraph);
		mGraphInsertEdge(g, jnuGraph, mode);
		fclose(jnuGraph);
	}
	else{
		puts("How many spots in your graph?");
		scanf("%d", &scale);
		getchar();
		g = createMGraph(scale,stdin);
		mGraphInsertEdge(g,stdin,mode);
	}
	Weight **D=createDistance(scale);
	vertex **Path=createPath(scale);
	system("cls");
	AllPairs(g, D, Path);

	menu(Path,D,g,printPath);

	system("pause");
	return 0;
}