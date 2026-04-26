*This project has been created as part of the 42 curriculum by <login1>.*

## Description

Inception is a system administration and DevOps-oriented project focused on containerization using Docker. The objective is to design and deploy a small infrastructure composed of multiple services, each running in its own container and orchestrated using Docker Compose.

The project enforces strict constraints: each service must be isolated, properly configured, and communicate through a Docker network. The infrastructure typically includes:

* NGINX (reverse proxy with TLS)
* WordPress (application layer)
* MariaDB (database)

The goal is to understand how modern applications are deployed in production using container-based architectures, emphasizing reproducibility, isolation, and scalability.

---

## Instructions

### Prerequisites

* Docker
* Docker Compose

### Setup

# Clone the repository
git clone <repository_url>
cd inception

### Build and Run
make up

### Access Services

* WordPress: [https://hounejja.42.fr](https://hounejja.42.fr)
* NGINX: handles incoming HTTPS requests

### Stop the Project

make down

## Docker Architecture & Design Choices

### Why Docker?

Docker provides lightweight virtualization through containers. Unlike traditional virtual machines, containers share the host kernel, making them faster to start, less resource-intensive, and easier to reproduce.

### Services Breakdown

* **NGINX**: Acts as a reverse proxy and handles HTTPS with TLS certificates.
* **WordPress**: PHP-based CMS served via PHP-FPM.
* **MariaDB**: Relational database storing WordPress data.

Each service runs in its own container to ensure modularity and separation of concerns.

## Technical Comparisons

### Virtual Machines vs Docker

| Virtual Machines     | Docker                  |
| -------------------- | ----------------------- |
| Full OS per instance | Shared host kernel      |
| Heavy resource usage | Lightweight             |
| Slow boot time       | Fast startup            |
| Strong isolation     | Process-level isolation |

Docker is preferred here for efficiency and ease of deployment.

### Secrets vs Environment Variables

| Secrets                                 | Environment Variables  |
| --------------------------------------- | ---------------------- |
| Secure storage                          | Plain text             |
| Not exposed in container runtime easily | Accessible via `env`   |
| Designed for sensitive data             | Used for configuration |

Secrets should be used for passwords, keys, and certificates, while environment variables are better suited for non-sensitive configuration.

---

### Docker Network vs Host Network

| Docker Network                       | Host Network         |
| ------------------------------------ | -------------------- |
| Isolated network layer               | Uses host networking |
| Container-to-container communication | No isolation         |
| DNS-based service discovery          | Manual configuration |

Docker networks provide better isolation and internal service discovery.

### Docker Volumes vs Bind Mounts

| Volumes                    | Bind Mounts               |
| -------------------------- | ------------------------- |
| Managed by Docker          | Managed by host           |
| Stored in Docker directory | Direct filesystem mapping |
| Better portability         | More control              |

Volumes are preferred for persistent data, while bind mounts are useful during development.

## Resources

### Documentation

* Docker Official Documentation: [https://docs.docker.com/](https://docs.docker.com/)
* Docker Compose Documentation: [https://docs.docker.com/compose/](https://docs.docker.com/compose/)
* NGINX Documentation: [https://nginx.org/en/docs/](https://nginx.org/en/docs/)
* WordPress Documentation: [https://wordpress.org/documentation/](https://wordpress.org/documentation/)
* MariaDB Documentation: [https://mariadb.org/documentation/](https://mariadb.org/documentation/)

### AI Usage

AI tools were used for:

* Understanding Docker networking and container orchestration concepts
* Debugging configuration issues
* Clarifying differences between Docker features (volumes, networks, secrets)

