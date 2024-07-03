#include <iostream>
using namespace std;

int maksimalDataSensorArray = 5, front = 0, back = 0;
struct DataSensor {
    string namaSensor;
    double nilaiSensor;
    string waktuPemantauan;
} dataSensorArray[5];


bool isFullArray()
{
    return (back == maksimalDataSensorArray);
}


bool isEmptyArray()
{
    return (back == 0);
}


void enqueueArray(string nama, double nilai, string waktu){
    if (isFullArray()) {
        cout << "Penyimpanan data sensor penuh!" << endl;
    } else {
        if (isEmptyArray()) {
            dataSensorArray[0] = {nama, nilai, waktu};
            front++;
            back++;
        } else {
            dataSensorArray[back] = {nama, nilai, waktu};
            back++;
        }
    }
}


void dequeueArray(){
    if (isEmptyArray()) {
        cout << "Data sensor kosong!" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            dataSensorArray[i] = dataSensorArray[i+1];
        }
        back--;
    }
}


int countArray()
{
    if (isEmptyArray()) {
        return 0;
    } else if (isFullArray()) {
        return maksimalDataSensorArray;
    } else {
        return back;
    }
}


void destroyArray(){
    if (isEmptyArray()) {
        cout << "Data sensor kosong!" << endl;
    } else {
        for (int i = 0; i < maksimalDataSensorArray; i++) {
            if (back > 1) {
                dataSensorArray[back - 1] = {"", 0, ""};
                back--;
            } else if (back == 1) {
                dataSensorArray[back - 1] = {"", 0, ""};
                back = 0;
                front = 0;
            }
        }
    }
}


void viewArray()
{
    cout << "Jumlah data sensor : " << countArray() << " data." << endl;
    cout << "Data Sensor : " << endl;
    if (isEmptyArray()) {
        cout << "Data sensor kosong!" << endl;
    } else {
        for (int i = 0; i < maksimalDataSensorArray; i++) {
            if (dataSensorArray[i].namaSensor != "") {
                cout << i+1 << ". " << dataSensorArray[i].namaSensor 
                     << " - " << dataSensorArray[i].nilaiSensor 
                     << " - " << dataSensorArray[i].waktuPemantauan << endl;
            } else {
                cout << i+1 << ". (kosong)" << endl;
            }
        }
    }
    cout << "\n" << endl;
}


struct DataSensorLL {
    string namaSensor;
    double nilaiSensor;
    string waktuPemantauan;
    DataSensorLL *next;
};

int maksimalDataSensorLinkedList = 5;
DataSensorLL *head, *tail, *cur, *del, *newNode;


int countLinkedList()
{
    if (head == NULL) {
        return 0;
    } else {
        int banyak = 0;
        cur = head;
        while (cur != NULL) {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}


bool isFullLinkedList()
{
    return (countLinkedList() == maksimalDataSensorLinkedList);
}


bool isEmptyLinkedList()
{
    return (countLinkedList() == 0);
}


void enqueueLinkedList(string nama, double nilai, string waktu) {
    if (isFullLinkedList()) {
        cout << "Penyimpanan Data Sensor Penuh!!!" << endl;
    } else {
        newNode = new DataSensorLL();
        newNode->namaSensor = nama;
        newNode->nilaiSensor = nilai;
        newNode->waktuPemantauan = waktu;
        newNode->next = NULL;
        
        if (isEmptyLinkedList()) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}


void dequeueLinkedList()
{
    if (isEmptyLinkedList()) {
        cout << "Data Sensor Kosong!!" << endl;
    } else {
        del = head;
        head = head->next;
        del->next = NULL;
        delete del;
    }
}


void clearLinkedList()
{
    if (isEmptyLinkedList()) {
        cout << "Data Sensor Kosong!!" << endl;
    } else {
        cur = head;
        while (cur != NULL) {
            del = cur;
            cur = cur->next;
            del->next = NULL;
            delete del;
        }
        head = NULL;
        tail = NULL;
    }
}


void displayLinkedList()
{
    cout << "Data Sensor : " << endl;
    if (isEmptyLinkedList()) {
        cout << "Data Sensor Kosong!!" << endl;
    } else {
        cout << "Banyak data sensor : " << countLinkedList() << endl;
        cur = head;
        int nomor = 1;
        while (nomor <= maksimalDataSensorLinkedList) {
            if (cur != NULL) {
                cout << nomor << ". " << cur->namaSensor << " - " 
                     << cur->nilaiSensor << " - " << cur->waktuPemantauan << endl;
                cur = cur->next;
            } else {
                cout << nomor << ". " << "(kosong)" << endl;
            }
            nomor++;
        }
    }
    cout << "\n" << endl;
}

int main()
{
    enqueueLinkedList("Suhu", 25.5, "2024-07-03 10:00");
    displayLinkedList();

    enqueueLinkedList("Kelembaban", 60.2, "2024-07-03 10:01");
    enqueueLinkedList("Tekanan", 1013.25, "2024-07-03 10:02");
    enqueueLinkedList("Kecepatan Angin", 5.7, "2024-07-03 10:03");
    enqueueLinkedList("Curah Hujan", 0.0, "2024-07-03 10:04");
    displayLinkedList();

    enqueueLinkedList("Intensitas Cahaya", 1000.0, "2024-07-03 10:05");
    displayLinkedList();

    dequeueLinkedList();
    displayLinkedList();

    clearLinkedList();
    displayLinkedList();

    cout << countLinkedList() << endl;

    return 0;
}