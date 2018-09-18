//this file is property of Red-Fleet
#include<stdio.h>
#include<stdlib.h>

struct matrix{
	long rows;
	long cols;
	double *data;
};

struct matrix* newMatrix(long rows, long cols){
	struct matrix *mat = (struct matrix *) malloc(sizeof(struct matrix));

	mat->rows = rows;
	mat->cols = cols;

	mat->data = (double *) malloc(rows * cols * sizeof(double));

	return mat;
}


void putMatrixElement(struct matrix* mat, long i, long j, double val){
	if(mat == NULL){
		printf("address is NULL");
		return;
	}


	  if(i >= mat->rows || j >= mat->cols){
     	         fputs("matrix out of index", stdout);
     	         return;
       	  }

	  mat->data[i * mat->cols + j] = val;
	  return;

}


double getMatrixElement(struct matrix* mat, long i, long j){
	if(mat == NULL){
                printf("address is NULL");
                return 0;
        }

	if(i >= mat->rows || j >= mat->cols){
		fputs("matrix out of index", stdout);
		return 0;
	}

	return mat->data[ i * mat->cols + j];
}

long countMatrixRows(struct matrix * mat){
	if(mat == NULL){
                printf("address is NULL");
                return 0;
        }

	return mat->rows;
}

long countMatrixCols(struct matrix * mat){
        if(mat == NULL){
                printf("address is NULL");
                return 0;
        }

	return mat->cols;
}

struct matrix* multiplyMatrixElementWise(struct matrix * mat1, struct matrix * mat2){
        if(mat1 == NULL || mat2 == NULL){
                printf("address is NULL");
                return NULL;
        }


        if(!(mat1->rows == mat2->rows && mat1->cols == mat2->cols)){
                fputs("cannot  multiply matrix element wise", stdout);
                return NULL;
        }

        struct matrix * mat3 = (struct matrix *) malloc(sizeof(struct matrix));

        long i, j, k;
        long rows = mat1->rows,  cols = mat1->cols;

        mat3->rows = rows;
        mat3->cols = cols;
        mat3->data = (double *) malloc(rows * cols * sizeof(double));

	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
			mat3->data[i*cols + j] = mat1->data[i*cols + j] * mat2->data[i*cols + j];

	return mat3;
}


struct matrix* multiplyMatrixDot(struct matrix * mat1, struct matrix * mat2){
        if(mat1 == NULL || mat2 == NULL){
                printf("address is NULL");
                return NULL;
        }

	if(mat1->cols != mat2->rows){
		fputs("cannot multiply matrix", stdout);
		return NULL;
	}

	struct matrix * mat3 = (struct matrix *) malloc(sizeof(struct matrix));

	long i, j, k;
	long rows = mat1->rows,  cols = mat2->cols, roco = mat1->cols;
	double num;

	mat3->rows = rows;
	mat3->cols = cols;
	mat3->data = (double *) malloc(rows * cols * sizeof(double));



	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			num = 0;
			for(k=0; k<roco; k++)
				num = num + mat1->data[i*roco + k] * mat2->data[cols*k + j];
			mat3->data[i*cols + j] = num;
		}
	}

	return mat3;
}


void  multiplyMatrixScaler(struct matrix * mat1, double a){
        if(mat1 == NULL){
                printf("address is NULL");
                return;
        }


        long i, j, k;
        long rows = mat1->rows,  cols = mat1->cols;

        for(i=0; i<rows; i++)
                for(j=0; j<cols; j++)
                        mat1->data[i*cols + j] = mat1->data[i*cols + j] * a;

        return ;
}

struct matrix* addMatrix(struct matrix * mat1, struct matrix * mat2){
        if(mat1 == NULL || mat2 == NULL){
                printf("address is NULL");
                return NULL;
        }

        if(!(mat1->rows == mat2->rows && mat1->cols == mat2->cols)){
                fputs("cannot add matrix", stdout);
                return NULL;
        }

        struct matrix * mat3 = (struct matrix *) malloc(sizeof(struct matrix));

        long i, j, k;
        long rows = mat1->rows,  cols = mat1->cols;

        mat3->rows = rows;
        mat3->cols = cols;
        mat3->data = (double *) malloc(rows * cols * sizeof(double));

        for(i=0; i<rows; i++)
                for(j=0; j<cols; j++)
                        mat3->data[i*cols + j] = mat1->data[i*cols + j] + mat2->data[i*cols + j];

        return mat3;
}



void addMatrixScaler(struct matrix * mat1, double a){

        if(mat1 == NULL){
                printf("address is NULL");
                return;
        }

        long i, j, k;
        long rows = mat1->rows,  cols = mat1->cols;


        for(i=0; i<rows; i++)
                for(j=0; j<cols; j++)
                        mat1->data[i*cols + j] = mat1->data[i*cols + j] + a;

        return;
}






struct matrix* subMatrix(struct matrix * mat1, struct matrix * mat2){
        if(mat1 == NULL || mat2 == NULL){
                printf("address is NULL");
                return NULL;
        }

        if(!(mat1->rows == mat2->rows && mat1->cols == mat2->cols)){
                fputs("cannot subtract matrix", stdout);
                return NULL;
        }

        struct matrix * mat3 = (struct matrix *) malloc(sizeof(struct matrix));

        long i, j, k;
        long rows = mat1->rows,  cols = mat1->cols;

        mat3->rows = rows;
        mat3->cols = cols;
        mat3->data = (double *) malloc(rows * cols * sizeof(double));

        for(i=0; i<rows; i++)
                for(j=0; j<cols; j++)
                        mat3->data[i*cols + j] = mat1->data[i*cols + j] - mat2->data[i*cols + j];

        return mat3;
}


void subMatrixScaler(struct matrix * mat1, double a){

        if(mat1 == NULL){
                printf("address is NULL");
                return;
        }

        long i, j, k;
        long rows = mat1->rows,  cols = mat1->cols;


        for(i=0; i<rows; i++)
                for(j=0; j<cols; j++)
                        mat1->data[i*cols + j] = mat1->data[i*cols + j] - a;

        return ;
}


void printMatrix(struct matrix * mat){
        if(mat == NULL){
                printf("address is NULL");
                return;
        }

	long rows = mat->rows;
	long cols = mat->cols;

	long i, j, k;

	for(i=0; i<rows; i++){
		printf("\n");
		k = i*cols;
		for(j=0; j<cols; j++)
			printf("%d ",(int)mat->data[k+j]);
	}
}


void initializeMatrix(struct matrix * mat, double val){
        if(mat == NULL){
                printf("address is NULL");
                return;
        }

        
	long rows = mat->rows;
        long cols = mat->cols;

        long i, j, k;

        for(i=0; i<rows; i++){
                k = i*cols;
                for(j=0; j<cols; j++)
                        mat->data[k+j] = val;
        }
}

struct matrix * concatMatrixRows(struct matrix * mat1, struct matrix * mat2){
        if(mat1 == NULL || mat2 == NULL){
                printf("address is NULL");
                return NULL;
        }

        if(!(mat1->rows == mat2->rows)){
                fputs("cannot concat matrix", stdout);
                return NULL;
        }

        long rows = mat1->rows;
        long cols = mat1->cols + mat2->cols;

        struct matrix * mat3 = newMatrix(rows, cols);

        long i, j , upto;

        upto = mat1->cols;
        for(i=0; i<rows; i++)
                for(j=0; j<upto; j++)
                        putMatrixElement(mat3, i, j, getMatrixElement(mat1 , i, j));


        for(i=0; i<rows; i++)
                for(j=upto; j<cols; j++)
                        putMatrixElement(mat3, i, j, getMatrixElement(mat2 , i, j-upto));

        return mat3;
}

void deleteMatrix(struct matrix* mat){
        if(mat == NULL){
                printf("address is NULL");
                return;
        }


	free(mat->data);
	free(mat);
}
