/* 
  파일이름: 주짓수 퍼포먼스 분석 시스템
  작 성 자: 설연희, 26-06-15
  하 는 일: 주짓수 퍼포먼스 분석 및 관원 관리 
*/

#include <stdio.h>

// [1] 기호 상수 정의 영역
#define MAX_MEMBERS 3

// main 함수로부터 배열의 주소들을 전달받아 루프를 돌며 다중 데이터를 안전하게 수집
void input_members(char names[][20], char genders[], int months[], int sp_counts[], double weights[], double hours[]) {
    printf("\n===  [1] 전 관원 데이터 일괄 입력 (총 %d명) ===\n", MAX_MEMBERS);
    
    for (int i = 0; i < MAX_MEMBERS; i++) {
        printf("\n[%d번째 관원 정보 입력]\n", i + 1);
        
        // 이니셜 1글자에서 문자열(영문 이름) 형식으로 확장
        printf("영문 이름 입력 (공백 없이): ");
        scanf("%s", names[i]); 
        
        printf("성별 입력 (남성: M, 여성: F): ");
        scanf(" %c", &genders[i]); // 입력 버퍼 찌꺼기 방지를 위해 공백 추가
        
        printf("수련 기간(개월)과 주간 스파링 횟수 입력 (예: 12 5): ");
        scanf("%d %d", &months[i], &sp_counts[i]);
        
        printf("현재 체중(kg) 입력: ");
        scanf("%lf", &weights[i]);
        
        printf("일주일 총 훈련 시간(시간) 입력: ");
        scanf("%lf", &hours[i]);
    }
    printf("\n>> 모든 관원의 기본 데이터 입력이 완료되었습니다!\n");
}

/ 함수 2. 전 관원 퍼포먼스 지수 일괄 계산 함수 (반환 및 포인터 효과 활용)
// 반복문을 순회하며 각 관원의 산술 연산을 수행하고 그 결과를 성장지수 배열에 직접 저장
void calculate_all(int months[], int sp_counts[], double hours[], double idx_arr[]) {
    for (int i = 0; i < MAX_MEMBERS; i++) {
        // 기존 1차 과제의 산술 연산 공식을 배열 원소별로 매핑하여 일괄 계산
        idx_arr[i] = (sp_counts[i] * 1.5) + (hours[i] / 2.0) + (months[i] * 0.1);
    }
    printf("\n>> 전 관원의 퍼포먼스 지수 산출 알고리즘 연산이 완료되었습니다.\n");
}
  
[2] 사용자 정의 함수 정의 영역 (모듈화 및 데이터 전달)
// [1] 전역 변수 선언 영역
// 프로그램이 종료될 때까지 성장 지수 데이터를 유지하고, 함수 내부에서 업데이트하기 위해 선언

// 함수 3. 종합 리포트 및 체급/승급 일괄 조회 함수 (중첩 조건문 결합 및 표 출력)
// 다중 조건 및 논리 연산자를 결합하여 전 관원의 데이터를 한눈에 표(Table) 형태
void print_all_reports(char names[][20], char genders[], int months[], int sp_counts[], double weights[], double hours[], double idx_arr[]) {
    printf("\n========================================================================================\n");
    printf(" 주짓수 관원 퍼포먼스 및 체급 관리 종합 리포트 (총 %d명)\n", MAX_MEMBERS);
    printf("========================================================================================\n");
    printf("이름\t성별\t체중\t수련기간\t주간기록\t\t성장지수\t체급 및 승급진단\n");
    printf("----------------------------------------------------------------------------------------\n");

for (int i = 0; i < MAX_MEMBERS; i++) {
// 1. 기본 인적 사항 및 수련 데이터 출력
        printf("%s\t%c\t%.1fkg\t%d개월\t\t%d회/%4.1f시간\t%.2f점\t", 
            names[i], genders[i], weights[i], months[i], sp_counts[i], hours[i], idx_arr[i]);

        // 2. 성별에 따른 중첩 및 다중 조건문 (체급 분류)
        if (genders[i] == 'M' || genders[i] == 'm') {
            if (weights[i] < 64.0) printf("[남성 페더급] ");
            else if (weights[i] < 70.0) printf("[남성 라이트급] ");
            else printf("[남성 미들급이상] ");
        } 
        else if (genders[i] == 'F' || genders[i] == 'f') {
            if (weights[i] < 53.0) printf("[여성 페더급] ");
            else if (weights[i] < 58.0) printf("[여성 라이트급] ");
            else printf("[여성 미들급이상] ");
        }
        else {
            printf("[체급 불명] ");
        }

        // 3. 논리 연산자(&&)를 활용한 승급 자격 종합 판단
        if (idx_arr[i] >= 50.0 && months[i] >= 6) {
            printf("승급심사 대상자\n");
        } else {
            printf("수련 요망\n");
        }
    }
    printf("========================================================================================\n");
}

// [3] 메인 로직 영역
int main() {
    // 4차 과제 핵심: 단일 지역 변수 구조를 기호상수(MAX_MEMBERS) 기반 배열 구조로 전면 확장
    char member_names[MAX_MEMBERS][20];       // 2차원 문자 배열 (관원 영문 이름 저장용)
    char member_genders[MAX_MEMBERS];          // 성별 배열
    int training_months[MAX_MEMBERS];         // 수련 기간 배열
    int sparring_counts[MAX_MEMBERS];          // 주간 스파링 횟수 배열
    double current_weights[MAX_MEMBERS];       // 현재 체중 배열
    double training_hours[MAX_MEMBERS];        // 주간 훈련 시간 배열
    double performance_indices[MAX_MEMBERS];   // 계산된 성장 지수 배열 (기존 global 변수 대체)
    
    int menu_choice; // 사용자의 메뉴 선택 번호를 담을 지역 변수

// while(1) 무한 루프 기반 메뉴 프레임워크
    while(1) {
        printf("\n--- 주짓수 통합 관원 관리 시스템 V4.0 ---\n");
        printf("1. 전 관원 정보 일괄 입력 (%d명)\n", MAX_MEMBERS);
        printf("2. 전 관원 성장 지수 일괄 계산\n");
        printf("3. 종합 리포트 및 체급/승급 조회\n");
        printf("0. 프로그램 종료\n");
        printf("--------------------------------------------------\n");
        printf("원하는 기능의 번호를 선택하세요: ");
        scanf("%d", &menu_choice);

// 입력받은 메뉴 번호에 따른 데이터 분기 처리 (독립된 함수 호출 구조)
        if (menu_choice == 1) {
            // 주소 참조를 통해 함수 내부에서 메인의 원본 배열 데이터를 채움
            input_members(member_names, member_genders, training_months, sparring_counts, current_weights, training_hours);
        } 
        else if (menu_choice == 2) {
            // 입력된 원본 배열 데이터를 가공하여 인덱스 배열을 생성
            calculate_all(training_months, sparring_counts, training_hours, performance_indices);
        } 
        else if (menu_choice == 3) {
            // 다중 결합된 데이터 리스트를 표 형태로 호출
            print_all_reports(member_names, member_genders, training_months, sparring_counts, current_weights, training_hours, performance_indices);
        } 
        else if (menu_choice == 0) {
            printf("\n시스템을 종료합니다. Oss!\n");
            break; // 루프 탈출 프로세스 종료
        } 
        else {
            printf("\n 잘못된 번호입니다. 0~3 사이의 번호를 입력해주세요.\n");
        }
    }

    return 0;
}


