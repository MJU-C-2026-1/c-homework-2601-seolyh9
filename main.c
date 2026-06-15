/* 
  파일이름: 주짓수 퍼포먼스 분석 시스템
  작 성 자: 설연희, 26-05-31
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

// [3] 메인 로직 영역 (목차형 구조 아키텍처 실현)

double global_performance_idx = 0.0;

// [2] 사용자 정의 함수 영역
// 함수 1. 성장 지수 계산 함수 (반환값 return 구조)
// 입력받은 정수와 실수 데이터를 인자로 받아 사칙연산을 수행하고 결과(double)를 반환

double calculate_score(int months, int sparring, double hours) {
    double score;
    // 1차 과제의 산술 연산 공식을 그대로 함수 내부로 이사했습니다.
    score = (sparring * 1.5) + (hours / 2.0) + (months * 0.1);
    return score; // 계산된 결과값을 호출한 곳으로 반환
}

// 함수 2. 분석 리포트 및 체급 출력 함수 (매개변수 전달 구조)
// main 함수로부터 모든 신체 데이터를 넘겨받아 성별/체급별 중첩 조건문을 실행하고 출력
void print_report(char initial, char gender, double weight, int months, int sparring, double hours) {
    printf("\n==========================================\n");
    printf("입력하신 [%c] 관원님의 분석 리포트입니다.\n", initial);
    printf("------------------------------------------\n");

    // 2차 과제 :  성별/체급별 중첩 및 다중 if문 
    if (gender == 'M' || gender == 'm') {
        printf("성별: 남성\t");
        if (weight < 64.0) printf("체급: 페더급\n");
        else if (weight < 70.0) printf("체급: 라이트급\n");
        else printf("체급: 미들급 이상\n");
    } 
    else if (gender == 'F' || gender == 'f') {
        printf("성별: 여성\t");
        if (weight < 53.0) printf("체급: 페더급\n");
        else if (weight < 58.0) printf("체급: 라이트급\n");
        else printf("체급: 미들급 이상\n");
    }
    else {
        printf("성별: 알 수 없음 (잘못된 입력)\n");
    }

    printf("현재 체중:\t%.2f kg\n", weight);
    printf("수련 기간:\t%d 개월\n", months);
    printf("주간 기록:\t%d회 스파링 / %.1f시간 훈련\n", sparring, hours);
    printf("------------------------------------------\n");
  
    // 전역 변수에 저장되어 있는 현재의 퍼포먼스 지수를 가져와 출력
    printf(">> 현재 누적 퍼포먼스 지수: %.2f 점\n", global_performance_idx);
    printf("==========================================\n");
}


// [3] 메인 로직 영역

int main() {
    // // 함수 내부에서만 사용되는 지역 변수 선언
    char user_initial = ' ';        // 사용자 이니셜
    char user_gender = ' ';         // 성별 (M/F) - V2.0 추가
    int training_months = 0;        // 수련 기간
    int sparring_count = 0;         // 주간 스파링 횟수
    double current_weight = 0.0;    // 현재 체중
    double training_hours = 0.0;    // 주간 훈련 시간
    double performance_idx; // 성장 지수
    
  int menu_choice; // 사용자의 메뉴 선택 번호를 담을 지역 변수
  
  // while(1) 무한 루프를 사용하여 프로그램이 계속 구동되도록 제어
    while(1) {
        printf("\n--- 🥋 주짓수 퍼포먼스 관리 시스템 V3.0 ---\n");
        printf("1. 관원 데이터 입력\n");
        printf("2. 분석 리포트 및 체급 조회\n");
        printf("3. 승급 자격 심사 진단\n");
        printf("0. 프로그램 종료\n");
        printf("------------------------------------------\n");
        printf("원하는 기능의 번호를 선택하세요: ");
        scanf("%d", &menu_choice);

        // 입력받은 메뉴 번호에 따른 데이터 분기 처리 (목차형 구조)
        if (menu_choice == 1) {
            printf("\n[1] 관원 데이터를 입력합니다.\n");
            printf("영문 이니셜 한 글자 입력: ");
            scanf(" %c", &user_initial);
            printf("성별 입력 (남성: M, 여성: F): ");
            scanf(" %c", &user_gender);
            printf("수련 기간(개월)과 주간 스파링 횟수 입력(예: 12 5): ");
            scanf("%d %d", &training_months, &sparring_count);
            printf("현재 체중(kg) 입력: ");
            scanf("%lf", &current_weight);
            printf("일주일 총 훈련 시간(시간) 입력: ");
            scanf("%lf", &training_hours);
         
          // 데이터 입력이 끝나면 계산 함수를 호출하여 전역 변수 값을 직접 업데이트
            global_performance_idx = calculate_score(training_months, sparring_count, training_hours);
            printf(">> 데이터 입력 및 퍼포먼스 지수 계산이 완료되었습니다.\n");
          } 
        else if (menu_choice == 2) {
            // 복잡한 출력 코드를 단 한 줄의 함수 호출로 간결하게 처리 (매개변수 전달)
            print_report(user_initial, user_gender, current_weight, training_months, sparring_count, training_hours);
        } 
        else if (menu_choice == 3) {
            printf("\n[3] 승급 자격 심사 진단 결과\n");
            // 논리 연산자(&&)와 전역 변수 값을 활용하여 자격을 판별
            if (global_performance_idx >= 50.0 && training_months >= 6) {
                printf(">> 🎉 축하합니다! [%c] 관원님은 승급 심사 대상자입니다.\n", user_initial);
            } else {
                printf(">> 🥋 수련을 지속하여 점수와 기간을 더 쌓으세요. (자격 미달)\n");
            }
        } 
        else if (menu_choice == 0) {
            // 사용자가 0번을 눌렀을 때만 break를 만나 무한 루프를 탈출하고 프로그램 종료
            printf("\n시스템을 종료합니다. 즐거운 수련 되세요! Oss!\n");
            break; 
        } 
        else {
            printf("\n🚨 잘못된 번호입니다. 0~3 사이의 번호를 입력해주세요.\n");
        }
    }

    return 0;
}
