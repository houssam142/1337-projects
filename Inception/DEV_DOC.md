
# 📄 `DEV_DOC.md`

# Developer Documentation

## Environment Setup

### Prerequisites

- Docker
- Docker Compose
- Make


## Project Structure

- docker-compose.yml: service definitions
- Makefile: automation commands
- requirements/: Dockerfiles and configurations for each service

## Configuration

Environment variables and credentials are defined in:

- `.env` file
- Docker Compose file
- Initialization scripts

Sensitive data should not be hardcoded.

## Build and Launch

Using Makefile:

make
