FROM registry.fedoraproject.org/fedora:latest AS builder
RUN mkdir /build
COPY . /build/
WORKDIR /build
RUN yum install "@Development Tools" -y
RUN make build

FROM registry.fedoraproject.org/fedora-minimal:latest
COPY --from=builder /build/_output/zombies /usr/bin/
RUN microdnf install iproute iputils net-tools procps-ng nmap-ncat kubernetes-client trace-cmd util-linux -y && \
    microdnf clean all
