#include <stdlib.h>
#include <stdio.h>

int main(){
	FILE *in_file, *out_file;

	int m, n, r, c;
	/* open in_matrix.txt for read */
	in_file = fopen("in_matrix.txt", "r");
	if(in_file == NULL)
		return -1;

	/* get matrix dimensions from file */
	fscanf(in_file, "%d %d", &m, &n);

	/* allocate matrix dynamically */
	int *in_matrix = (int *)malloc(sizeof(int)*m*n);
	/* get matrix elements from file */
	for(r=0;r<m;r++){
		for(c=0;c<n;c++){
			fscanf(in_file, "%d", in_matrix+(r*n+c));
		}
	}
	
	/* close in_matrix.txt */
	fclose(in_file);

	/* open out_matrix.txt for write */
	out_file = fopen("out_matrix.txt", "w");
	if(out_file == NULL)
		return -1;

	/* write transposed matrix dimensions to file */
	fprintf(out_file, "%d %d\n", n, m);

	/* write transposed matrix elements to file */
	for(c=0;c<n;c++){
		for(r=0;r<m;r++){
			fprintf(out_file, "%d ", in_matrix[r*n+c]);
		}
		fprintf(out_file, "\n");
	}

	/* close out_matrix.txt */
	fclose(out_file);

	/* deallocate array */
	free(in_matrix);
	return 0;
}
