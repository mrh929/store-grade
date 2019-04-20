#include<cstdio>
#include<cstdlib>
#include<cstring>

struct Student{
	char sno[12];
    char sname[10];
    char sex[4];
    char major[20];
    Student *next; //指向后继数据结点
}*StudentList;

struct Course{
	char cno[10];
	char cname[20];
	int classHours;
	Course *next;
}*CourseList;

struct Grade{
	char sno[12];
    char cno[10];
    int score ;
    Grade *next;
}*GradeList;

FILE *Open_File(int who, int rw){//打开哪个文件，打开方式如何 
	FILE *p;
	switch(who){
		case 1:{
			if(rw) p = fopen("student.dat","w");
			else p = fopen("student.dat","r");
			break;
		}
		case 2:{
			if(rw) p = fopen("course.dat","w");
			else p = fopen("course.dat","r");
			break;
		}
		case 3:{
			if(rw) p = fopen("courseGrade.dat","w");
			else p = fopen("courseGrade.dat","r");
			break;
		}
		
	}
	return p;
}

/*
	 以下是关于学生的代码 
*/

Student* Read_Student(){
	FILE *StuFile = Open_File(1, 0);//read
	Student *head = (Student *) malloc(sizeof(Student));
	Student *pre = head;
	while(!feof(StuFile)){
		Student *p = (Student *) malloc(sizeof(Student));
		fscanf(StuFile, "%s%s%s%s", p->sno, p->sname, p->sex, p->major);
		pre->next = p;
		pre = p;
	}
	pre->next = NULL;
	
	fclose(StuFile);
	return head;
}

void BubbleSort_Student(){
	for(int i = 1; i <= 10; i++){
		Student *p = StudentList->next;
		Student *pre = StudentList;
		while(p != NULL && p->next != NULL ){//存在两个可以比较的结点 
			Student *pnext = p->next;
			if(strcmp(p->sno, pnext->sno) > 0){
				pre->next = pnext;
				p->next = pnext->next;
				pnext->next = p;	
			}
			pre = p;
			p = p->next;
		}
	}
	
	
}

void Print_Student(){
	Student *p = StudentList->next;
	printf("\nStudentList");
	printf("\n---------------------\n");
	while(p != NULL){
		printf("%s %s %s %s", p->sno, p->sname, p->sex, p->major);
		p = p->next;
		if(p != NULL) printf("\n");
	}
	printf("\n---------------------\n\n");
}

void Write_Student(){
	FILE *StuFile = Open_File(1, 1);//write
	Student *p = (Student *) malloc(sizeof(Student));
	for(int i = 1; i <= 10; i++){
		printf("No.%2d:", i);
		scanf("%s%s%s%s", p->sno, p->sname, p->sex, p->major);
		fprintf(StuFile, "%s %s %s %s", p->sno, p->sname, p->sex, p->major);
		if(i != 10) fprintf(StuFile, "\n");
	}
	free(p);
	fclose(StuFile);
	return;
}


/*
	 以下是关于课程的代码 
*/

Course* Read_Course(){
	FILE *CourseFile = Open_File(2, 0);//read
	Course *head = (Course *) malloc(sizeof(Course));
	Course *pre = head;
	while(!feof(CourseFile)){
		Course *p = (Course *) malloc(sizeof(Course));
		fscanf(CourseFile, "%s%s%d", p->cno, p->cname, &p->classHours);
		pre->next = p;
		pre = p;
	}
	pre->next = NULL;
	
	fclose(CourseFile);
	return head;
}

void BubbleSort_Course(){
	for(int i = 1; i <= 10; i++){
		Course *p = CourseList->next;
		Course *pre = CourseList;
		while(p != NULL && p->next != NULL ){//存在两个可以比较的结点 
			Course *pnext = p->next;
			if(strcmp(p->cno, pnext->cno) > 0){
				pre->next = pnext;
				p->next = pnext->next;
				pnext->next = p;	
			}
			pre = p;
			p = p->next;
		}
	}
	
	
}

void Print_Course(){
	Course *p = CourseList->next;
	printf("\nCourseList");
	printf("\n---------------------\n");
	while(p != NULL){
		printf("%s %s %d", p->cno, p->cname, p->classHours);
		p = p->next;
		if(p != NULL) printf("\n");
	}
	printf("\n---------------------\n\n");
}

void Write_Course(){
	FILE *CourseFile = Open_File(2, 1);//write
	Course *p = (Course *) malloc(sizeof(Course));
	for(int i = 1; i <= 3; i++){
		printf("No.%2d:", i);
		scanf("%s%s%d", p->cno, p->cname, &p->classHours);
		fprintf(CourseFile, "%s %s %d", p->cno, p->cname, p->classHours);
		if(i != 3) fprintf(CourseFile, "\n");
	}
	free(p);
	fclose(CourseFile);
	return;
}


/*
	 以下是关于成绩的代码 
*/

Grade* Read_Grade(){
	FILE *GradeFile = Open_File(3, 0);//read
	Grade *head = (Grade *) malloc(sizeof(Grade));
	Grade *pre = head;
	while(!feof(GradeFile)){
		Grade *p = (Grade *) malloc(sizeof(Grade));
		fscanf(GradeFile, "%s%s%d", p->sno, p->cno, &p->score);
		pre->next = p;
		pre = p;
	}
	pre->next = NULL;
	
	fclose(GradeFile);
	return head;
}

void BubbleSort_Grade(){
	for(int i = 1; i <= 10; i++){
		Grade *p = GradeList->next;
		Grade *pre = GradeList;
		while(p != NULL && p->next != NULL ){//存在两个可以比较的结点 
			Grade *pnext = p->next;
			if(strcmp(p->sno, pnext->sno) > 0 || (strcmp(p->sno, pnext->sno) == 0 && strcmp(p->cno, pnext->cno) > 0) ){
				pre->next = pnext;
				p->next = pnext->next;
				pnext->next = p;	
			}
			
			
			pre = p;
			p = p->next;
		}
	}
}

void Print_Grade(){
	Grade *p = GradeList->next;
	printf("\nGradeList");
	printf("\n---------------------\n");
	while(p != NULL){
		printf("%s %s %d", p->sno, p->cno, p->score);
		p = p->next;
		if(p != NULL) printf("\n");
	}
	printf("\n---------------------\n\n");
}

void Write_Grade(){
	FILE *GradeFile = Open_File(3, 1);//write
	Grade *p = (Grade *) malloc(sizeof(Grade));
	for(int i = 1; i <= 10; i++){
		printf("No.%2d:", i);
		scanf("%s%s%d", p->sno, p->cno, &p->score);
		fprintf(GradeFile, "%s %s %d", p->sno, p->cno, p->score);
		if(i != 10) fprintf(GradeFile, "\n");
	}
	free(p);
	fclose(GradeFile);
	return;
}


void ReverseStudent(){
	Student *head = (Student*) malloc(sizeof(Student));
	Student *p = StudentList->next;
	head->next = NULL;
	
	while(p != NULL){
		Student *t = p->next;//暂时保存p的下一个结点 
		
		p->next = head->next;
		head->next = p;
		p = t;
	}
	
	StudentList = head;
}

int main(){
	int opt;
	Student *HEAD = NULL;
	printf("Welcome to Students' score system!\n");
	
	while(1){
		printf("\nPlease input an option:");	
		scanf("%d", &opt);
		if(opt == -1) break;
		switch(opt){
			case 1:{
				Write_Student();
				printf("done.\n");
				break;
			}
			
			case 2:{
				Write_Course();
				printf("done.\n");
				break;
			}
			
			case 3:{
				Write_Grade();
				printf("done.\n");
				break;
			}
			
			case 4:{
				StudentList = Read_Student();
				BubbleSort_Student();
				Print_Student();
				break;
			}
			
			case 5:{
				CourseList = Read_Course();
				BubbleSort_Course();
				Print_Course();
				break;
			}
			
			case 6:{
				GradeList = Read_Grade();
				BubbleSort_Grade();
				Print_Grade();
				break;
			}
			
			case 7:{
				StudentList = Read_Student();
				CourseList = Read_Course();
				GradeList = Read_Grade();
				
				
				
				break;
			}
			
			case 10:{
				ReverseStudent();//逆序生成新的链表 
				Print_Student();//输出该链表 
				break;
			}
		}
		
	}
	
}
