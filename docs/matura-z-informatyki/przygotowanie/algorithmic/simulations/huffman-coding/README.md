# Kody Huffmana

## Opis algorytmu

[huffman-coding.md](../../../../../algorithms/coding-and-compression/huffman-coding.md)

## Zadanie 1

Dany jest następujący tekst w języku angielskim, zapisany poniżej. Zgodnie z algorytmem kodowania Huffmana stwórz i rozrysuj drzewo kodów, a następnie zakoduj podany tekst za jego pomocą. Oblicz uzyskany stopień kompresji z dokładnością do dwóch miejsc po przecinku, zakładając, że oryginalny tekst był zakodowany za pomocą standardowego kodu ASCII, gdzie każdy znak to jeden bajt.

**Pamiętaj**: możliwe jest uzyskanie kilku różnych, **prawidłowych** drzew kodów.

> **knowledge_is_power**

## Zadanie 2

Poniżej podane jest drzewo kodów Huffmana, a następnie zakodowana wiadomość. Odkoduj wiadomość na podstawie drzewa, a także oblicz stopień kompresji z dokładnością do dwóch miejsc po przecinku, przyjmując jeden bajt na każdy znak w oryginalnym tekście.

### Drzewo kodów

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
	n19((20)) --0--> n17((8))
	n19((20)) --1--> n18((12))
	n18((12)) --0--> n15((5))
	n18((12)) --1--> n16((7))
	n16((7)) --0--> n7(("3|l"))
	n16((7)) --1--> n9(("4|e"))
	n15((5)) --0--> n12((2))
	n15((5)) --1--> n4(("3|_"))
	n12((2)) --0--> n6(("1|i"))
	n12((2)) --1--> n8(("1|t"))
	n17((8)) --0--> n13((4))
	n17((8)) --1--> n14((4))
	n14((4)) --0--> n5(("2|h"))
	n14((4)) --1--> n11((2))
	n11((2)) --0--> n0(("1|r"))
	n11((2)) --1--> n3(("1|s"))
	n13((4)) --0--> n1(("2|p"))
	n13((4)) --1--> n2(("2|o"))
```

### Wiadomość

```
0101111101101011000011110100110010101110110101000111001000110111
```