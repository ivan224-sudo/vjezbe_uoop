#pragma once
#include <stdexcept>
#include <string>

class NeisparavnaStruktura : public std::runtime_error {
public:
    explicit NeisparavnaStruktura(const std::string& poruka)
        : std::runtime_error("Neispravna struktura: " + poruka) {}
};

class ProizvodNijePronadjen : public std::runtime_error {
public:
    explicit ProizvodNijePronadjen(int sifra)
        : std::runtime_error("Proizvod sa sifrom " + std::to_string(sifra) + " nije pronaden.") {}
};
