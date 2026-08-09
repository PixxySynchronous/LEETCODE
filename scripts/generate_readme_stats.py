#!/usr/bin/env python3
"""Regenerates the progress-stats section of README.md by counting solution
files under each tracked category folder, broken down by topic subfolder.

Run manually with: python3 scripts/generate_readme_stats.py
"""

import os
import sys

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
README_PATH = os.path.join(REPO_ROOT, "README.md")

CATEGORIES = ["DSA-DOUBT", "DSA-NO-DOUBT", "DSA-IMPOSSIBLE", "Patterns", "SQL"]
EXCLUDED_FILENAMES = {".DS_Store"}
ROOT_LABEL = "(General)"

START_MARKER = "<!-- STATS:START -->"
END_MARKER = "<!-- STATS:END -->"


def count_category(category_path):
    """Returns {topic_label: file_count} for a category directory."""
    breakdown = {}
    for dirpath, _dirnames, filenames in os.walk(category_path):
        files = [f for f in filenames if f not in EXCLUDED_FILENAMES]
        if not files:
            continue
        rel = os.path.relpath(dirpath, category_path)
        topic = ROOT_LABEL if rel == "." else rel.split(os.sep)[0]
        breakdown[topic] = breakdown.get(topic, 0) + len(files)
    return breakdown


def build_stats_markdown():
    category_breakdowns = {}
    grand_total = 0

    for category in CATEGORIES:
        category_path = os.path.join(REPO_ROOT, category)
        if not os.path.isdir(category_path):
            continue
        breakdown = count_category(category_path)
        category_breakdowns[category] = breakdown
        grand_total += sum(breakdown.values())

    lines = []
    lines.append("## Progress Stats")
    lines.append("")
    lines.append(f"**Total Questions Solved: {grand_total}**")
    lines.append("")
    lines.append("```mermaid")
    lines.append(
        "%%{init: {'theme': 'base', 'themeVariables': {"
        "'pie1': '#ff595e', 'pie2': '#ff924c', 'pie3': '#ffca3a', 'pie4': '#c5ca30',"
        "'pie5': '#8ac926', 'pie6': '#36949d', 'pie7': '#1982c4', 'pie8': '#4267ac',"
        "'pie9': '#565aa0', 'pie10': '#6a4c93', 'pie11': '#b5179e', 'pie12': '#f15bb5',"
        "'pieOpacity': '1', 'pieStrokeColor': '#00000022', 'pieOuterStrokeWidth': '0'"
        "}}}%%"
    )
    lines.append("pie showData")
    lines.append('    title Questions Solved by Topic')
    for category, breakdown in category_breakdowns.items():
        for topic in sorted(breakdown, key=lambda t: (t == ROOT_LABEL, t.lower())):
            label = category if topic == ROOT_LABEL else f"{category}: {topic}"
            lines.append(f'    "{label}" : {breakdown[topic]}')
    lines.append("```")
    lines.append("")

    for category, breakdown in category_breakdowns.items():
        category_total = sum(breakdown.values())
        lines.append(f"### {category} ({category_total})")
        lines.append("")
        lines.append('<div align="center">')
        lines.append("")
        lines.append("| Topic | Count |")
        lines.append("|---|---|")
        for topic in sorted(breakdown, key=lambda t: (t == ROOT_LABEL, t.lower())):
            lines.append(f"| {topic} | {breakdown[topic]} |")
        lines.append("")
        lines.append("</div>")
        lines.append("")

    return "\n".join(lines).rstrip("\n")


def update_readme(stats_markdown):
    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    if START_MARKER not in content or END_MARKER not in content:
        print(f"Error: markers {START_MARKER} / {END_MARKER} not found in README.md", file=sys.stderr)
        sys.exit(1)

    before = content.split(START_MARKER)[0]
    after = content.split(END_MARKER)[1]
    new_content = f"{before}{START_MARKER}\n{stats_markdown}\n{END_MARKER}{after}"

    if new_content == content:
        print("README.md stats already up to date.")
        return False

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(new_content)
    print("README.md stats updated.")
    return True


if __name__ == "__main__":
    update_readme(build_stats_markdown())
