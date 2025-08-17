#include "common.h"

Communicator::Communicator(CommParams& pars, QWidget* parent) {
    par = pars;
    readyToRecieve = bind(par.senderHost, par.senderPort, QAbstractSocket::DontShareAddress	| QAbstractSocket::ReuseAddressHint);
    if (readyToRecieve) connect(this, QUdpSocket::readyRead, this, Communicator::recieve);
}

bool Communicator::isReady() {
    return readyToRecieve;
}

void Communicator::send(QByteArray data) {
    if (readyToRecieve) {
        writeDatagram(data, par.recieverHost, par.recieverPort);
    }
}

void Communicator::recieve() {
    if (hasPendingDatagrams()) {
        quint64 size = pendingDatagramSize();
        QByteArray msg(size, '\0');
        readDatagram(msg.data(), size);
        emit recieved(msg);
    }
}
