#include <stdio.h>
int n_case, n_node; // ���̽� ���� ��� ���� ��� ����
int maze[50][50] = { 0 }; // matrix 2���� �迭, �ִ�ũ�� 50x50
int visit[50];
int size;
int result = 0;

void reset_visit() {
    for (int i = 0; i < size; i++) {
        visit[i] = 0;
    }
}

void test(int n) {
    visit[n] = 1; // �湮�Ҷ����� 1�� �ٲ��ش�.
    for (int i = 0; i < size; i++) {
        if (maze[n][i] == 1) {
            if (visit[i] == 1) { // ��湮�̸� ����Ŭ
                result = 1;
                break;
            }
            else {
                test(i);     
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n_case);
    for (int n = 0; n < n_case; n++) {
        scanf("%d", &n_node);
        size = n_node;
        for (int i = 0; i < n_node; i++) {
            for (int j = 0; j < n_node; j++) {
                scanf("%d", &maze[i][j]);
            }
        }
        for (int i = 0; i < n_node; i++) {
            for (int j = 0; j < n_node; j++) {
                // 0���� ��� ������ �� �����ϱ� ���� 1�� ������ ������ test�Լ� ȣ��
                if (maze[i][j] == 1) {
                    test(i);
                    reset_visit();
                    goto After;
                }
            }
        }
        After: printf("%d\n", result);
        result = 0;
    }
    return 0;
}