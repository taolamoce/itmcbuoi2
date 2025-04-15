#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

class LoginWindow : public QWidget {
public:
    LoginWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Đăng nhập");

        QLabel *labelUser = new QLabel("Tên đăng nhập:");
        QLabel *labelPass = new QLabel("Mật khẩu:");

        userInput = new QLineEdit();
        passInput = new QLineEdit();
        passInput->setEchoMode(QLineEdit::Password);

        QPushButton *loginButton = new QPushButton("Đăng nhập");

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(labelUser);
        layout->addWidget(userInput);
        layout->addWidget(labelPass);
        layout->addWidget(passInput);
        layout->addWidget(loginButton);

        setLayout(layout);

        connect(loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);
    }

private:
    QLineEdit *userInput;
    QLineEdit *passInput;

    void handleLogin() {
        QString username = userInput->text();
        QString password = passInput->text();

        if (username == "admin" && password == "123456") {
            QMessageBox::information(this, "Thông báo", "Đăng nhập thành công!");
        } else {
            QMessageBox::warning(this, "Lỗi", "Sai tài khoản hoặc mật khẩu!");
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    LoginWindow login;
    login.show();
    return app.exec();
}
