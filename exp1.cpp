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

struct allinfo{
	
	
	
};

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

void BubbleSort_StudentsGrade(){
	for(int i = 1; i <= 10; i++){
		Grade *p = GradeList->next;
		Grade *pre = GradeList;
		while(p != NULL && p->next != NULL ){//存在两个可以比较的结点 
			Grade *pnext = p->next;
			if(p->score < pnext->score){
				pre->next = pnext;
				p->next = pnext->next;
				pnext->next = p;	
			}
			pre = p;
			p = p->next;
		}
	}
}

Student *Find_Student(char *num){
	Student *p = StudentList->next;
	do{
		if(strcmp(p->sno, num) == 0) return p;
		p = p->next;
	}while(p != NULL);
	
	p = (Student*) malloc(sizeof(Student));
	char temp[3] = "-1";
	strcpy(p->major, temp);
	strcpy(p->sex, temp);
	strcpy(p->sname, temp);
	strcpy(p->sno, temp);
	p->next = NULL;
	return p;//返回错误 
}

Course *Find_Course(char *num){
	Course *p = CourseList->next;
	do{
		if(strcmp(p->cno, num) == 0) return p;
		p = p->next;
	}while(p != NULL);
	
	p = (Course*) malloc(sizeof(Course));
	char temp[3] = "-1";
	strcpy(p->cname, temp);
	strcpy(p->cno, temp);
	p->classHours = -1;
	p->next = NULL;
	return p;//返回错误 
}

void Print_All(Grade *p){
	Student *s = Find_Student(p->sno);
	Course *c = Find_Course(p->cno);
	printf("%6s %6s %6s %6s %3d", s->sno, s->sname, s->major, c->cname, p->score);
}

void Print_Seven(){//Task7 
	Grade *p = GradeList->next;
	printf("\nGradeList");
	printf("\nnumber   name  major  course  grade");
	printf("\n---------------------------------------\n");
	while(p != NULL){
		Print_All(p);
		p = p->next;
		if(p != NULL) printf("\n");
	}
	printf("\n---------------------------------------\n\n");
}

void Print_Eight(char* num){//Task8 指定课程号 
	Grade *p = GradeList->next;
	printf("\nGradeList");
	printf("\nnumber   name  major  course  grade");
	printf("\n---------------------------------------\n");
	while(p != NULL){
		if(strcmp(p->cno, num) == 0) Print_All(p);
		p = p->next;
		if(p != NULL) printf("\n");
	}
	printf("\n---------------------------------------\n\n");
}

void Print_Nine(){//Task9 
	Grade *p = GradeList->next;
	printf("\nGradeList");
	printf("\nnumber   name  major  course  grade");
	printf("\n---------------------------------------\n");
	while(p != NULL){
		if(p->score < 60) Print_All(p);
		p = p->next;
		if(p != NULL) printf("\n");
	}
	printf("\n---------------------------------------\n\n");
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
	printf("1.Input students.\n");
	printf("2.Input courses.\n");
	printf("3.Input grades.\n");
	printf("4.Output students.\n");
	printf("5.Output courses.\n");
	printf("6.Output grades.\n");
	printf("7.Output all.\n");
	printf("8.Output all of a course.\n");
	printf("9.Output all below 60.\n");
	printf("10.Reverse students.\n");
	printf("11.Output all.\n");
	
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
				BubbleSort_StudentsGrade();//按照成绩排序 
				Print_Seven();
				
				break;
			}
			
			case 8:{
				StudentList = Read_Student();
				CourseList = Read_Course();
				GradeList = Read_Grade();
				BubbleSort_StudentsGrade();//按照成绩排序 
				char str[10];
				printf("input course name:");
				scanf("%s", str);
				Print_Eight(str);
				
				break;
			}
			
			case 9:{
				StudentList = Read_Student();
				CourseList = Read_Course();
				GradeList = Read_Grade();
				BubbleSort_StudentsGrade();//按照成绩排序 
				Print_Nine();
				
				break;
			}
			
			case 10:{
				StudentList = Read_Student();
				ReverseStudent();//逆序生成新的链表 
				Print_Student();//输出该链表 
				break;
			}
			
			case 11:{
				StudentList = Read_Student();
				CourseList = Read_Course();
				GradeList = Read_Grade();
				BubbleSort_StudentsGrade();//按照成绩排序 
				Print_Seven();
				
				
				break;
			}
		}
		
	}
	
}
