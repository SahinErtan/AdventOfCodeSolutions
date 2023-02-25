
overlaped_section_count = 0

with open("input.txt") as f:
    for section_pairs in f:
        section_pairs.replace("\n","")
        pairs = section_pairs.split(",")

        sections1 = pairs[0].split("-")
        sections2 = pairs[1].split("-")

        section11 = int(sections1[0])
        section12 = int(sections1[1])
        section21 = int(sections2[0])
        section22 = int(sections2[1])

        if section11 in range(section21, section22 + 1, 1):
            overlaped_section_count += 1
        elif section12 in range(section21, section22 + 1, 1):
            overlaped_section_count += 1
        elif section21 in range(section11, section12 + 1, 1):
            overlaped_section_count += 1
        elif section22 in range(section11, section12 + 1, 1):
            overlaped_section_count += 1

print(overlaped_section_count)
# 861