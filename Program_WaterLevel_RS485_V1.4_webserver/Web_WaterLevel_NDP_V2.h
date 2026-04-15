const char main_page_html[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang="en">
  <head>
    <title>Water Level Monitoring</title>
    <meta property="og:title" content="Water Level Monitoring" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta charset="utf-8" />
    <meta property="twitter:card" content="summary_large_image" />

    <style data-tag="reset-style-sheet">
      html {
        line-height: 1.15;
      }
      body {
        margin: 0;
      }
      * {
        box-sizing: border-box;
        border-width: 0;
        border-style: solid;
        -webkit-font-smoothing: antialiased;
      }
      p,
      li,
      ul,
      pre,
      div,
      h1,
      h2,
      h3,
      h4,
      h5,
      h6,
      figure,
      blockquote,
      figcaption {
        margin: 0;
        padding: 0;
      }
      button {
        background-color: transparent;
      }
      button,
      input,
      optgroup,
      select,
      textarea {
        font-family: inherit;
        font-size: 100%;
        line-height: 1.15;
        margin: 0;
      }
      button,
      select {
        text-transform: none;
      }
      button,
      [type="button"],
      [type="reset"],
      [type="submit"] {
        -webkit-appearance: button;
        color: inherit;
      }
      button::-moz-focus-inner,
      [type="button"]::-moz-focus-inner,
      [type="reset"]::-moz-focus-inner,
      [type="submit"]::-moz-focus-inner {
        border-style: none;
        padding: 0;
      }
      button:-moz-focus,
      [type="button"]:-moz-focus,
      [type="reset"]:-moz-focus,
      [type="submit"]:-moz-focus {
        outline: 1px dotted ButtonText;
      }
      a {
        color: inherit;
        text-decoration: inherit;
      }
      pre {
        white-space: normal;
      }
      input {
        padding: 2px 4px;
      }
      img {
        display: block;
      }
      details {
        display: block;
        margin: 0;
        padding: 0;
      }
      summary::-webkit-details-marker {
        display: none;
      }
      [data-thq="accordion"] [data-thq="accordion-content"] {
        max-height: 0;
        overflow: hidden;
        transition: max-height 0.3s ease-in-out;
        padding: 0;
      }
      [data-thq="accordion"]
        details[data-thq="accordion-trigger"][open]
        + [data-thq="accordion-content"] {
        max-height: 1000vh;
      }
      details[data-thq="accordion-trigger"][open]
        summary
        [data-thq="accordion-icon"] {
        transform: rotate(180deg);
      }
      html {
        scroll-behavior: smooth;
      }
    </style>
    <style data-tag="default-style-sheet">
      html {
        font-family: "Nunito Sans";
        font-size: 1rem;
      }

      body {
        font-weight: 400;
        font-style: normal;
        text-decoration: undefined;
        text-transform: undefined;
        letter-spacing: 0.01em;
        line-height: 1.6;
        color: var(--color-on-surface);
        background: var(--color-surface);

        fill: var(--color-on-surface);
      }
    </style>

    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Inter:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&amp;display=swap"
      data-tag="font"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=STIX+Two+Text:ital,wght@0,400;0,500;0,600;0,700;1,400;1,500;1,600;1,700&amp;display=swap"
      data-tag="font"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Noto+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&amp;display=swap"
      data-tag="font"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Nunito+Sans:ital,wght@0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&amp;display=swap"
      data-tag="font"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Rubik:ital,wght@0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,300;1,400;1,500;1,600;1,700;1,800;1,900&amp;display=swap"
      data-tag="font"
    />

    <style>
      /* index.css */

      /* Styling Dasar untuk Setiap Bar (Lebih Tebal) */
      .bar {
        width: 8px; /* Ditingkatkan dari 4px menjadi 8px (lebih tebal) */
        margin-right: 2px; /* Jarak antar bar */
        background-color: #2e7bd3;
        transition:
          height 0.3s,
          background-color 0.3s;
      }

      /* Ketinggian Spesifik Setiap Bar (Ditingkatkan) */
      .bar-1 {
        margin-top: 20px;
        height: 10px;
      } /* Ditingkatkan dari 5px menjadi 10px */
      .bar-2 {
        margin-top: 10px;
        height: 20px;
      } /* Ditingkatkan dari 10px menjadi 20px */
      .bar-3 {
        height: 30px;
      } /* Ditingkatkan dari 15px menjadi 30px */

      /* Kelas Warna Sinyal (Tetap sama) */
      .bar-red {
        background-color: #ff4d4d;
      }
      .bar-orange {
        background-color: #ffa500;
      }
      .bar-green {
        background-color: #4caf50;
      }

      .navigation-wrapper {
        display: contents;
      }

      .navigation-container1 {
        display: contents;
      }

      .navigation-container2 {
        display: none;
      }

      .navigation-container3 {
        display: contents;
      }

      .navigation-container4 {
        display: none;
      }

      .navigation-container5 {
        display: contents;
      }

      .footer-wrapper {
        display: contents;
      }

      .footer-container1 {
        display: contents;
      }

      .footer-container2 {
        display: none;
      }

      .footer-container3 {
        display: contents;
      }

      .footer-container4 {
        display: none;
      }

      .footer-container5 {
        display: contents;
      }

      .home-container1 {
        width: 100%;
        display: block;
        min-height: 100vh;
      }

      .home-text11 {
        font-weight: 700;
      }

      .home-thq-action-icon-elm1 {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .home-thq-action-label-elm1 {
        font-weight: var(--font-weight-medium);
      }

      .home-thq-action-icon-elm2 {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .home-thq-action-label-elm2 {
        font-weight: var(--font-weight-medium);
      }

      .home-thq-action-icon-elm3 {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .home-thq-action-label-elm3 {
        font-weight: var(--font-weight-medium);
      }

      .home-thq-action-icon-elm4 {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .home-thq-action-label-elm4 {
        font-weight: var(--font-weight-medium);
      }

      .home-container2 {
        display: none;
      }

      .home-container3 {
        display: contents;
      }

      .home-container4 {
        right: 50px;
        border: 1px solid #ffffff5c;
        bottom: 30px;
        display: flex;
        z-index: 22;
        position: fixed;
        box-shadow: 5px 5px 10px 0px rgba(31, 31, 31, 0.4);
        min-height: auto;
        align-items: center;
        padding-top: 8px;
        padding-left: 12px;
        border-radius: 8px;
        padding-right: 12px;
        padding-bottom: 8px;
        backdrop-filter: blur(6px);
        background-color: rgba(41, 41, 41, 0.41);
      }

      .home-icon37 {
        width: 24px;
        margin-right: 4px;
      }

      .home-text40 {
        color: white;
        font-size: 13px;
        font-style: normal;
        font-weight: 500;
        line-height: 24px;
      }

      /* style.css */
      :root {
        --spacing-lg: 1rem;
        --spacing-md: 0.75rem;
        --spacing-sm: 0.5rem;
        --spacing-xl: 1.5rem;
        --spacing-xs: 0.25rem;
        --color-scrim: color-mix(in oklab, #ffffff 70%, transparent);
        --spacing-2xl: 2rem;
        --spacing-3xl: 3rem;
        --spacing-4xl: 4rem;
        --color-accent: #a8ff00;
        --color-border: #303033;
        --font-size-lg: clamp(1.1rem, 1rem + 0.5vw, 1.25rem);
        --font-size-sm: clamp(0.85rem, 0.75rem + 0.25vw, 0.95rem);
        --font-size-xl: clamp(1.4rem, 1.2rem + 0.9vw, 1.6rem);
        --font-size-xs: clamp(0.65rem, 0.55rem + 0.2vw, 0.8rem);
        --color-neutral: #303033;
        --color-outline: #00c2a8;
        --color-overlay: color-mix(in oklab, #ffffff 40%, transparent);
        --color-primary: #007aff;
        --color-surface: #121212;
        --divider-value: 0px none var(--color-border);
        --font-size-2xl: clamp(1.8rem, 1.6rem + 1.1vw, 2rem);
        --font-size-3xl: clamp(2.2rem, 2rem + 1.6vw, 2.8rem);
        --font-size-4xl: clamp(3rem, 2.6rem + 2.2vw, 4.2rem);
        --font-size-base: 1rem;
        --shadow-level-1: 0 4px 12px rgba(100, 50, 200, 0.15);
        --shadow-level-2: 0 12px 32px rgba(100, 50, 200, 0.2);
        --shadow-level-3: 0 24px 60px rgba(100, 50, 200, 0.25);
        --color-backplate: color-mix(in oklab, #ffffff 60%, transparent);
        --color-on-accent: #000000;
        --color-secondary: #00b89a;
        --border-radius-lg: 24px;
        --border-radius-md: 16px;
        --border-radius-sm: 8px;
        --border-radius-xl: 40px;
        --color-on-primary: #ffffff;
        --color-on-surface: #f6fbff;
        --font-family-body:
          "Nunito Sans", system-ui, -apple-system, "Segoe UI", Roboto,
          "Helvetica Neue", Arial;
        --font-weight-body: 400;
        --line-height-body: 1.6;
        --content-max-width: 84rem;
        --border-radius-card: 24px;
        --border-radius-full: 9999px;
        --border-radius-none: 0px;
        --color-on-secondary: #ffffff;
        --font-style-heading: normal;
        --font-weight-medium: 600;
        --font-family-heading:
          "Rubik", system-ui, -apple-system, "Segoe UI", Roboto,
          "Helvetica Neue", Arial;
        --font-weight-heading: 700;
        --letter-spacing-body: 0.01em;
        --line-height-heading: 1.25;
        --dl-layout-size-large: 144px;
        --dl-layout-size-small: 48px;
        --dl-layout-space-unit: 16px;
        --border-radius-control: 16px;
        --dl-layout-size-medium: 96px;
        --dl-layout-size-xlarge: 192px;
        --dl-layout-size-xsmall: 16px;
        --font-style-subheading: italic;
        --color-surface-elevated: color-mix(in oklab, #121212 92%, #00b89a);
        --dl-color-theme-accent1: #ffffff;
        --dl-color-theme-accent2: #f5d1b0;
        --dl-layout-radius-round: 50%;
        --dl-layout-size-xxlarge: 288px;
        --letter-spacing-heading: 0.02em;
        --text-transform-heading: none;
        --dl-color-theme-primary1: #bf4408;
        --dl-color-theme-primary2: #e65103;
        --dl-layout-size-maxwidth: 1400px;
        --dl-layout-radius-radius2: 2px;
        --dl-layout-radius-radius4: 4px;
        --dl-layout-radius-radius8: 8px;
        --dl-layout-space-halfunit: 8px;
        --dl-layout-space-sixunits: 96px;
        --dl-layout-space-twounits: 32px;
        --dl-color-theme-secondary1: #ffffff;
        --dl-color-theme-secondary2: #fbf1eb;
        --dl-layout-space-fiveunits: 80px;
        --dl-layout-space-fourunits: 64px;
        --color-on-surface-secondary: #b9c4ce;
        --dl-layout-space-threeunits: 48px;
        --dl-color-theme-neutral-dark: #191818;
        --dl-layout-radius-cardradius: 8px;
        --dl-color-theme-neutral-light: #fbfaf9;
        --dl-layout-radius-imageradius: 8px;
        --dl-layout-radius-inputradius: 24px;
        --dl-layout-radius-buttonradius: 24px;
        --dl-layout-space-oneandhalfunits: 24px;
      }

      .button {
        color: var(--dl-color-theme-neutral-dark);
        display: inline-block;
        padding: 0.5rem 1rem;
        border-color: var(--dl-color-theme-neutral-dark);
        border-width: 1px;
        border-radius: 4px;
        background-color: var(--dl-color-theme-neutral-light);
      }

      .input {
        color: var(--dl-color-theme-neutral-dark);
        cursor: auto;
        padding: 0.5rem 1rem;
        border-color: var(--dl-color-theme-neutral-dark);
        border-width: 1px;
        border-radius: 4px;
        background-color: var(--dl-color-theme-neutral-light);
      }

      .textarea {
        color: var(--dl-color-theme-neutral-dark);
        cursor: auto;
        padding: 0.5rem;
        border-color: var(--dl-color-theme-neutral-dark);
        border-width: 1px;
        border-radius: 4px;
        background-color: var(--dl-color-theme-neutral-light);
      }

      .list {
        width: 100%;
        margin: 1em 0px 1em 0px;
        display: block;
        padding: 0px 0px 0px 1.5rem;
        list-style-type: none;
        list-style-position: outside;
      }

      .list-item {
        display: list-item;
      }

      .teleport-show {
        display: flex !important;
        transform: none !important;
      }

      .thq-input {
        color: var(--dl-color-theme-neutral-dark);
        cursor: auto;
        outline: none;
        padding: 0.5rem 1rem;
        align-self: stretch;
        text-align: center;
        border-color: var(--dl-color-theme-neutral-dark);
        border-width: 1px;
        border-radius: var(--dl-layout-radius-inputradius);
        background-color: var(--dl-color-theme-neutral-light);
      }

      .thq-input:focus {
        outline: 1px solid var(--dl-color-theme-primary1);
      }

      .thq-button-filled {
        gap: var(--dl-layout-space-halfunit);
        fill: var(--dl-color-theme-secondary1);
        color: var(--dl-color-theme-secondary1);
        cursor: pointer;
        display: flex;
        transition: 0.3s;
        align-items: center;
        font-weight: bold;
        padding-top: var(--dl-layout-space-halfunit);
        white-space: nowrap;
        border-color: var(--dl-color-theme-primary1);
        border-width: 1px;
        padding-left: var(--dl-layout-space-oneandhalfunits);
        border-radius: var(--dl-layout-radius-buttonradius);
        padding-right: var(--dl-layout-space-oneandhalfunits);
        padding-bottom: var(--dl-layout-space-halfunit);
        justify-content: center;
        background-color: var(--dl-color-theme-primary1);
      }

      .thq-button-filled:hover {
        fill: var(--dl-color-theme-secondary2);
        color: var(--dl-color-theme-secondary2);
        border-color: var(--dl-color-theme-primary2);
        background-color: var(--dl-color-theme-primary2);
      }

      .thq-button-outline {
        gap: var(--dl-layout-space-halfunit);
        fill: var(--dl-color-theme-primary1);
        color: var(--dl-color-theme-primary1);
        border: 1px solid;
        cursor: pointer;
        display: flex;
        transition: 0.3s;
        align-items: center;
        font-weight: bold;
        padding-top: var(--dl-layout-space-halfunit);
        white-space: nowrap;
        border-color: var(--dl-color-theme-primary1);
        padding-left: var(--dl-layout-space-oneandhalfunits);
        border-radius: var(--dl-layout-radius-buttonradius);
        padding-right: var(--dl-layout-space-oneandhalfunits);
        padding-bottom: var(--dl-layout-space-halfunit);
        justify-content: center;
      }

      .thq-button-outline:hover {
        fill: var(--dl-color-theme-secondary2);
        color: var(--dl-color-theme-secondary2);
        border-color: var(--dl-color-theme-primary2);
        background-color: var(--dl-color-theme-primary2);
      }

      .thq-button-flat {
        gap: var(--dl-layout-space-halfunit);
        fill: var(--dl-color-theme-primary1);
        color: var(--dl-color-theme-primary1);
        cursor: pointer;
        display: flex;
        transition: 0.3s;
        align-items: center;
        font-weight: bold;
        padding-top: var(--dl-layout-space-halfunit);
        white-space: nowrap;
        border-color: transparent;
        border-width: 1px;
        padding-left: var(--dl-layout-space-oneandhalfunits);
        border-radius: var(--dl-layout-radius-buttonradius);
        padding-right: var(--dl-layout-space-oneandhalfunits);
        padding-bottom: var(--dl-layout-space-halfunit);
        justify-content: center;
      }

      .thq-button-flat:hover {
        fill: var(--dl-color-theme-secondary1);
        color: var(--dl-color-theme-secondary1);
        border-color: var(--dl-color-theme-primary2);
        background-color: var(--dl-color-theme-primary2);
      }

      .thq-heading-1 {
        font-size: 48px;
        font-family: STIX Two Text;
        font-weight: 700;
        line-height: 1.5;
      }

      .thq-heading-2 {
        font-size: 35px;
        font-family: STIX Two Text;
        font-weight: 600;
        line-height: 1.5;
      }

      .thq-heading-3 {
        font-size: 26px;
        font-family: STIX Two Text;
        font-weight: 600;
        line-height: 1.5;
      }

      .thq-body-large {
        font-size: 18px;
        font-family: Noto Sans;
        line-height: 1.5;
      }

      .thq-body-small {
        font-size: 16px;
        font-family: Noto Sans;
        line-height: 1.5;
      }

      .thq-team-image-round {
        width: 80px;
        height: 80px;
        object-fit: cover;
        border-radius: 50%;
      }

      .thq-section-padding {
        width: 100%;
        display: flex;
        padding: var(--dl-layout-space-fiveunits);
        position: relative;
        align-items: center;
        flex-direction: column;
      }

      .thq-section-max-width {
        width: 100%;
        max-width: var(--dl-layout-size-maxwidth);
      }

      .thq-img-ratio-1-1 {
        width: 100%;
        object-fit: cover;
        aspect-ratio: 1/1;
        border-radius: var(--dl-layout-radius-imageradius);
      }

      .thq-img-ratio-16-9 {
        width: 100%;
        object-fit: cover;
        aspect-ratio: 16/9;
        border-radius: var(--dl-layout-radius-imageradius);
      }

      .thq-img-ratio-4-3 {
        width: 100%;
        object-fit: cover;
        aspect-ratio: 4/3;
        border-radius: var(--dl-layout-radius-imageradius);
      }

      .thq-img-ratio-4-6 {
        width: 100%;
        object-fit: cover;
        aspect-ratio: 4/6;
        border-radius: var(--dl-layout-radius-imageradius);
      }

      .thq-img-round {
        width: 100%;
        border-radius: var(--dl-layout-radius-round);
      }

      .thq-flex-column {
        gap: var(--dl-layout-space-twounits);
        display: flex;
        overflow: hidden;
        position: relative;
        align-items: center;
        flex-direction: column;
      }

      .thq-flex-row {
        gap: var(--dl-layout-space-twounits);
        display: flex;
        overflow: hidden;
        position: relative;
        align-items: center;
      }

      .thq-grid-6 {
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr 1fr 1fr 1fr 1fr;
      }

      .thq-grid-5 {
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr 1fr 1fr 1fr;
      }

      .thq-card {
        gap: var(--dl-layout-space-oneandhalfunits);
        display: flex;
        padding: var(--dl-layout-space-twounits);
        align-items: stretch;
        border-radius: var(--dl-layout-radius-cardradius);
        flex-direction: column;
      }

      .thq-box-shadow {
        box-shadow: 0px 0px 5px -2px var(--dl-color-theme-neutral-dark);
      }

      .thq-grid-3 {
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr 1fr;
      }

      .thq-grid-4 {
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr 1fr 1fr;
      }

      .thq-grid-2 {
        width: 100%;
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr;
      }

      .thq-checkbox {
        width: var(--dl-layout-size-xsmall);
        height: var(--dl-layout-size-xsmall);
      }

      .thq-select {
        cursor: pointer;
        appearance: none;
        padding-top: var(--dl-layout-space-halfunit);
        padding-left: var(--dl-layout-space-unit);
        border-radius: var(--dl-layout-radius-inputradius);
        padding-right: var(--dl-layout-space-twounits);
        padding-bottom: var(--dl-layout-space-halfunit);
        background-color: var(--dl-color-theme-neutral-light);
        background-image: url("data:image/svg+xml;charset=US-ASCII,%3Csvg width%3D%2220%22 height%3D%2220%22 xmlns%3D%22http%3A//www.w3.org/2000/svg%22 viewBox%3D%220 0 20 20%22 fill%3D%22%23000%22%3E%3Cpath d%3D%22M4.293 7.293a1 1 0 011.414 0L10 11.586l4.293-4.293a1 1 0 111.414 1.414l-5 5a1 1 0 01-1.414 0l-5-5a1 1 0 010-1.414z%22/%3E%3C/svg%3E");
        background-repeat: no-repeat;
        background-position: right 8px center;
      }

      .thq-divider-horizontal {
        width: 100%;
        height: 1px;
        background-color: var(--dl-color-theme-neutral-dark);
      }

      .thq-icon-small {
        width: 24px;
        height: 24px;
      }

      .thq-button-icon {
        fill: var(--dl-color-theme-secondary1);
        padding: 3px;
        transition: 0.3s;
        border-radius: var(--dl-layout-radius-round);
      }

      .thq-button-icon:hover {
        fill: var(--dl-color-theme-secondary2);
      }

      .thq-icon-medium {
        width: var(--dl-layout-size-small);
        height: var(--dl-layout-size-small);
      }

      .thq-icon-x-small {
        width: var(--dl-layout-size-xsmall);
        height: var(--dl-layout-size-xsmall);
      }

      .thq-link {
        cursor: pointer;
        display: inline-block;
        overflow: hidden;
        background: linear-gradient(
          to right,
          var(--dl-color-theme-primary1) 50%,
          var(--dl-color-theme-neutral-dark) 50%
        );
        transition: background-position 300ms ease;
        font-weight: 600;
        background-clip: text;
        background-size: 200% 100%;
        background-position: 100%;
        -webkit-text-fill-color: transparent;
      }

      .thq-link:hover {
        background-position: 0 100%;
      }

      .thq-grid-auto-300 {
        display: grid;
        grid-gap: var(--dl-layout-space-oneandhalfunits);
        grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
      }

      .thq-animated-group-vertical-reverse {
        gap: var(--dl-layout-space-unit);
        width: 100%;
        display: flex;
        animation: scroll-y 20s linear infinite;
        align-items: flex-start;
        flex-direction: column;
        justify-content: space-around;
        animation-direction: reverse;
      }

      .thq-animated-group-horizontal-reverse {
        gap: var(--dl-layout-space-unit);
        display: flex;
        animation: scroll-x 20s linear infinite;
        min-width: 100%;
        align-items: center;
        flex-shrink: 0;
        justify-content: space-around;
        animation-direction: reverse;
      }

      .thq-animated-group-vertical {
        gap: var(--dl-layout-space-unit);
        width: 100%;
        display: flex;
        animation: scroll-y 20s linear infinite;
        align-items: flex-start;
        flex-direction: column;
        justify-content: space-around;
      }

      .thq-animated-group-horizontal {
        gap: var(--dl-layout-space-unit);
        display: flex;
        animation: scroll-x 20s linear infinite;
        min-width: 100%;
        align-items: center;
        flex-shrink: 0;
        justify-content: space-around;
      }

      .thq-animated-group-container-vertical {
        gap: var(--dl-layout-space-unit);
        display: flex;
        overflow: hidden;
        flex-direction: column;
      }

      .thq-animated-group-container-horizontal {
        gap: var(--dl-layout-space-unit);
        display: flex;
        overflow: hidden;
      }

      .thq-mask-image-vertical {
        mask-image: linear-gradient(
          to bottom,
          transparent,
          black 1%,
          black 99%,
          transparent
        );
      }

      .thq-mask-image-horizontal {
        mask-image: linear-gradient(
          to right,
          transparent,
          black 1%,
          black 99%,
          transparent
        );
      }

      .thq-img-scale {
        transition: 0.3s;
      }

      .thq-img-scale:hover {
        scale: 1.05;
      }

      .thq-animated-card-bg-1 {
        width: 100%;
        height: 100%;
        transition: transform 0.3s;
        border-radius: var(--dl-layout-radius-cardradius);
        background-color: var(--dl-color-theme-accent1);
      }

      .thq-animated-card-bg-2 {
        transition: transform 0.3s;
        border-radius: var(--dl-layout-radius-cardradius);
        background-color: var(--dl-color-theme-accent2);
      }

      .thq-button-animated {
        outline: none;
        z-index: 1;
        overflow: hidden;
        position: relative;
        border-width: 2px;
      }

      .thq-input::placeholder {
        text-align: center;
        vertical-align: middle;
      }

      .thq-animated-group-container-vertical:hover div {
        animation-play-state: paused;
      }

      .thq-animated-group-container-horizontal:hover div {
        animation-play-state: paused;
      }

      .thq-animated-card-bg-2:has([data-animated="true"]:hover) {
        transform: translate3d(0px, 0px, 0px) scale3d(1, 1, 1) rotateX(0deg)
          rotateY(0deg) rotateZ(3deg) skew(0deg, 0deg);
      }

      .thq-animated-card-bg-1:has([data-animated="true"]:hover) {
        transform: translate3d(0px, 0px, 0px) scale3d(1, 1, 1) rotateX(0deg)
          rotateY(0deg) rotateZ(-6deg) skew(0deg, 0deg);
      }

      .thq-button-animated:before {
        top: 0;
        left: -20%;
        color: var(--dl-color-theme-neutral-light);
        width: 200%;
        height: 101%;
        content: "";
        z-index: 1;
        position: absolute;
        transform: scaleX(0);
        transition: transform 0.5s;
        border-radius: var(--dl-layout-radius-buttonradius);
        background-color: var(--dl-color-theme-neutral-dark);
        transform-origin: 0 0;
        transition-timing-function: cubic-bezier(0.5, 1.6, 0.4, 0.7);
      }

      .thq-button-animated:hover::before {
        color: var(--dl-color-theme-neutral-light);
        z-index: -1;
        transform: scaleX(1);
      }

      .btn {
        gap: var(--spacing-xs);
        border: 1px solid transparent;
        cursor: pointer;
        display: inline-flex;
        padding: var(--spacing-md) var(--spacing-lg);
        font-size: var(--font-size-base);
        box-shadow: var(--shadow-level-1);
        text-align: center;
        transition: all 0.2s ease-in-out;
        align-items: center;
        font-family: var(--font-family-body);
        font-weight: var(--font-weight-medium);
        line-height: var(--line-height-body);
        user-select: none;
        white-space: nowrap;
        border-radius: var(--border-radius-control);
        justify-content: center;
        text-decoration: none;
      }

      .btn-primary {
        color: var(--color-on-primary);
        border-color: var(--color-primary);
        background-color: var(--color-primary);
      }

      .btn-secondary {
        color: var(--color-on-secondary);
        border-color: var(--color-secondary);
        background-color: var(--color-secondary);
      }

      .btn-accent {
        color: var(--color-on-accent);
        border-color: var(--color-accent);
        background-color: var(--color-accent);
      }

      .btn-outline {
        color: var(--color-primary);
        border: 1px solid var(--color-primary);
        background-color: var(--color-surface);
      }

      .btn-link {
        color: var(--color-primary);
        box-shadow: none;
        border-color: transparent;
        text-decoration: underline;
        background-color: transparent;
      }

      .btn-sm {
        padding: var(--spacing-sm) var(--spacing-md);
      }

      .btn-lg {
        padding: var(--spacing-lg) var(--spacing-xl);
      }

      .btn-xl {
        padding: var(--spacing-xl) var(--spacing-2xl);
      }

      .section-title {
        font-size: var(--font-size-3xl);
        font-style: var(--font-style-heading);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        line-height: var(--line-height-heading);
        letter-spacing: var(--letter-spacing-heading);
        text-transform: var(--text-transform-heading);
      }

      .section-subtitle {
        opacity: 0.85;
        font-size: var(--font-size-lg);
        font-style: var(--font-style-subheading);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        line-height: var(--line-height-heading);
      }

      .section-content {
        font-size: var(--font-size-base);
        font-family: var(--font-family-body);
        font-weight: var(--font-weight-body);
        line-height: var(--line-height-body);
        letter-spacing: var(--letter-spacing-body);
      }

      .hero-title {
        font-size: var(--font-size-4xl);
        font-style: var(--font-style-heading);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        line-height: var(--line-height-heading);
        letter-spacing: var(--letter-spacing-heading);
        text-transform: var(--text-transform-heading);
      }

      .hero-subtitle {
        opacity: 0.85;
        font-size: var(--font-size-lg);
        font-style: var(--font-style-subheading);
        font-family: var(--font-family-body);
        font-weight: var(--font-weight-body);
        line-height: var(--line-height-body);
      }

      .btn:focus-visible {
        outline: 2px solid var(--color-outline);
        outline-offset: 2px;
      }

      .btn:disabled {
        cursor: not-allowed;
        opacity: 0.6;
        pointer-events: none;
      }

      .btn-primary:hover:not(:disabled) {
        border-color: color-mix(
          in oklab,
          var(--color-primary) 90%,
          var(--color-surface)
        );
        background-color: color-mix(
          in oklab,
          var(--color-primary) 90%,
          var(--color-surface)
        );
      }

      .btn-secondary:hover:not(:disabled) {
        border-color: color-mix(
          in oklab,
          var(--color-secondary) 90%,
          var(--color-surface)
        );
        background-color: color-mix(
          in oklab,
          var(--color-secondary) 90%,
          var(--color-surface)
        );
      }

      .btn-accent:hover:not(:disabled) {
        border-color: color-mix(
          in oklab,
          var(--color-accent) 90%,
          var(--color-surface)
        );
        background-color: color-mix(
          in oklab,
          var(--color-accent) 90%,
          var(--color-surface)
        );
      }

      .btn-outline:hover:not(:disabled) {
        color: var(--color-on-primary);
        border-color: var(--color-primary);
        background-color: var(--color-primary);
      }

      .btn-link:hover:not(:disabled) {
        color: color-mix(in oklab, var(--color-primary) 80%, black);
        text-decoration: underline;
      }

      .navigation-container {
        top: 0;
        left: 0;
        width: 100%;
        z-index: 1000;
        position: sticky;
        background: var(--color-surface);
        transition: background 0.3s ease;
        border-bottom: 1px solid var(--color-border);
      }

      .navigation-wrapper {
        margin: 0 auto;
        display: flex;
        padding: var(--spacing-md) var(--spacing-xl);
        max-width: var(--content-max-width);
        min-height: 4.5rem;
        align-items: center;
        justify-content: space-between;
      }

      .navigation-brand {
        gap: var(--spacing-sm);
        color: var(--color-on-surface);
        display: flex;
        transition: opacity 0.2s ease;
        align-items: center;
        text-decoration: none;
      }

      .navigation-links-desktop {
        gap: var(--spacing-2xl);
        display: flex;
        align-items: center;
      }

      .navigation-toggle {
        color: var(--color-on-surface);
        border: 1px solid var(--color-border);
        cursor: pointer;
        display: none;
        padding: var(--spacing-sm);
        background: transparent;
        transition: all 0.2s ease;
        border-radius: var(--border-radius-sm);
      }

      .navigation-logo-icon {
        color: var(--color-primary);
        width: 2.5rem;
        height: 2.5rem;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 15%, transparent);
        align-items: center;
        border-radius: var(--border-radius-md);
        justify-content: center;
      }

      .navigation-link {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-sm);
        transition: color 0.2s ease;
        font-family: var(--font-family-body);
        font-weight: var(--font-weight-medium);
        white-space: nowrap;
        text-decoration: none;
      }

      .navigation-mobile-overlay {
        inset: 0;
        display: none;
        z-index: 1100;
        position: fixed;
        transform: translateX(100%);
        background: var(--color-surface);
        min-height: 100vh;
        overflow-y: auto;
        transition: transform 0.4s cubic-bezier(0.16, 1, 0.3, 1);
        flex-direction: column;
      }

      .navigation-mobile-header {
        top: 0;
        display: flex;
        padding: var(--spacing-md) var(--spacing-xl);
        z-index: 1110;
        position: sticky;
        background: var(--color-surface);
        align-items: center;
        border-bottom: 1px solid var(--color-border);
        justify-content: space-between;
      }

      .navigation-mobile-content {
        gap: var(--spacing-4xl);
        flex: 1;
        display: flex;
        padding: var(--spacing-3xl) var(--spacing-xl);
        flex-direction: column;
      }

      .navigation-close {
        color: var(--color-on-surface);
        border: none;
        cursor: pointer;
        padding: var(--spacing-sm);
        background: transparent;
      }

      .navigation-mobile-links {
        gap: var(--spacing-xl);
        display: flex;
        flex-direction: column;
      }

      .navigation-mobile-footer {
        gap: var(--spacing-lg);
        display: flex;
        margin-top: auto;
        flex-direction: column;
        padding-bottom: var(--spacing-2xl);
      }

      .navigation-mobile-link {
        color: var(--color-on-surface);
        font-size: var(--font-size-3xl);
        transition:
          transform 0.2s ease,
          color 0.2s ease;
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        text-decoration: none;
      }

      .navigation-brand:hover {
        opacity: 0.8;
      }

      .navigation-brand .section-title {
        margin: 0;
        font-size: var(--font-size-xl);
      }

      .navigation-link:hover {
        color: var(--color-primary);
      }

      .navigation-toggle:hover {
        background: var(--color-surface-elevated);
        border-color: var(--color-primary);
      }

      .navigation-mobile-overlay.is-open {
        display: flex;
        transform: translateX(0);
      }

      .navigation-mobile-link:hover {
        color: var(--color-primary);
        transform: translateX(10px);
      }

      .navigation-mobile-footer .section-content {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-xs);
      }

      .footer-root {
        color: var(--color-on-surface);
        padding: var(--spacing-4xl) 0 var(--spacing-xl);
        overflow: hidden;
        position: relative;
        border-top: 1px solid var(--color-border);
        background-color: var(--color-surface);
      }

      .footer-glass-overlay {
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        z-index: 1;
        position: absolute;
        background:
          radial-gradient(
            circle at 10% 10%,
            color-mix(in srgb, var(--color-primary) 5%, transparent),
            transparent 40%
          ),
          radial-gradient(
            circle at 90% 90%,
            color-mix(in srgb, var(--color-secondary) 5%, transparent),
            transparent 40%
          );
        pointer-events: none;
      }

      .footer-container {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        z-index: 2;
        position: relative;
        max-width: var(--content-max-width);
      }

      .footer-grid {
        gap: var(--spacing-4xl);
        display: grid;
        margin-bottom: var(--spacing-4xl);
        grid-template-columns: 1.5fr 1fr 1fr;
      }

      .footer-bottom {
        padding-top: var(--spacing-2xl);
      }

      .footer-brand-col {
        gap: var(--spacing-xl);
        display: flex;
        flex-direction: column;
      }

      .footer-divider {
        width: 100%;
        height: 1px;
        background: linear-gradient(
          to right,
          transparent,
          var(--color-border),
          transparent
        );
        margin-bottom: var(--spacing-2xl);
      }

      .footer-legal-wrap {
        gap: var(--spacing-lg);
        display: flex;
        flex-wrap: wrap;
        align-items: center;
        justify-content: space-between;
      }

      .footer-logo-wrap {
        gap: var(--spacing-md);
        display: flex;
        align-items: center;
      }

      .footer-description {
        color: var(--color-on-surface-secondary);
        max-width: 400px;
      }

      .footer-social-links {
        gap: var(--spacing-md);
        display: flex;
      }

      .footer-col-title {
        color: var(--color-on-surface);
        display: inline-block;
        position: relative;
        margin-bottom: var(--spacing-xl);
      }

      .footer-nav-list {
        gap: var(--spacing-lg);
        margin: 0;
        display: flex;
        padding: 0;
        list-style: none;
        flex-direction: column;
      }

      .footer-nav-links {
        gap: var(--spacing-md);
        display: flex;
        flex-direction: column;
      }

      .footer-copyright {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-sm);
      }

      .footer-status-indicator {
        gap: var(--spacing-sm);
        border: 1px solid var(--color-border);
        display: flex;
        padding: var(--spacing-xs) var(--spacing-md);
        background: var(--color-surface-elevated);
        align-items: center;
        border-radius: var(--border-radius-full);
      }

      .footer-logo-icon {
        color: var(--color-on-primary);
        width: 40px;
        height: 40px;
        display: flex;
        background: var(--color-primary);
        box-shadow: 0 4px 12px
          color-mix(in srgb, var(--color-primary) 30%, transparent);
        align-items: center;
        border-radius: var(--border-radius-md);
        justify-content: center;
      }

      .footer-brand-name {
        color: var(--color-on-surface);
        font-size: var(--font-size-xl);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        letter-spacing: var(--letter-spacing-heading);
      }

      .footer-social-icon {
        color: var(--color-on-surface);
        width: 44px;
        border: 1px solid var(--color-border);
        height: 44px;
        display: flex;
        background: var(--color-surface-elevated);
        transition: all 0.3s ease;
        align-items: center;
        border-radius: var(--border-radius-full);
        justify-content: center;
        text-decoration: none;
      }

      .footer-nav-item {
        gap: var(--spacing-md);
        color: var(--color-on-surface-secondary);
        display: flex;
        align-items: center;
      }

      .footer-link {
        color: var(--color-on-surface-secondary);
        width: fit-content;
        display: inline-block;
        transition:
          color 0.2s ease,
          transform 0.2s ease;
        text-decoration: none;
      }

      .footer-status-dot {
        width: 8px;
        height: 8px;
        animation: pulse-status 2s infinite;
        box-shadow: 0 0 8px #2ecc71;
        border-radius: 50%;
        background-color: #2ecc71;
      }

      .footer-status-text {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-xs);
        font-weight: var(--font-weight-medium);
      }

      .footer-nav-icon {
        color: var(--color-secondary);
        width: 20px;
        height: 20px;
        display: flex;
        align-items: center;
        justify-content: center;
      }

      .footer-social-icon:hover {
        color: var(--color-on-primary);
        transform: translateY(-3px);
        background: var(--color-primary);
        border-color: var(--color-primary);
      }

      .footer-col-title::after {
        left: 0;
        width: 24px;
        bottom: -4px;
        height: 2px;
        content: "";
        position: absolute;
        background: var(--color-accent);
      }

      .footer-link:hover {
        color: var(--color-accent);
        transform: translateX(4px);
      }

      .aqua-dashboard {
        color: var(--color-on-surface);
        font-family: var(--font-family-body);
        line-height: var(--line-height-body);
        background-color: var(--color-surface);
      }

      .live-snapshot {
        padding: var(--spacing-4xl) 0;
        overflow: hidden;
        position: relative;
        background: linear-gradient(
          135deg,
          color-mix(in srgb, var(--color-primary) 15%, transparent),
          var(--color-surface)
        );
      }

      .quick-stats {
        padding: var(--spacing-4xl) 0;
        background: var(--color-surface);
      }

      .recent-trends {
        padding: var(--spacing-4xl) 0;
        background: color-mix(
          in srgb,
          var(--color-secondary) 5%,
          var(--color-surface)
        );
      }

      .alerts-summary {
        padding: var(--spacing-2xl) var(--spacing-xl);
      }

      .device-health {
        padding: var(--spacing-4xl) 0;
      }

      .recent-events {
        padding: var(--spacing-4xl) 0;
        background: var(--color-surface-elevated);
      }

      .quick-actions {
        padding: var(--spacing-4xl) 0;
      }

      .live-snapshot-container {
        gap: var(--spacing-4xl);
        margin: 0 auto;
        display: flex;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
        align-items: center;
      }

      .quick-stats-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .recent-trends-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .alert-banner {
        gap: var(--spacing-xl);
        display: flex;
        padding: var(--spacing-xl);
        background: color-mix(
          in srgb,
          #e74c3c 15%,
          var(--color-surface-elevated)
        );
        align-items: center;
        border-left: 4px solid #e74c3c;
        border-radius: var(--border-radius-md);
        justify-content: space-between;
      }

      .device-health-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .recent-events-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .quick-actions-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .live-snapshot-content {
        flex: 1;
      }

      .live-snapshot-readout {
        gap: var(--spacing-lg);
        flex: 1;
        display: flex;
        flex-direction: column;
      }

      .quick-stats-grid {
        gap: var(--spacing-xl);
        display: grid;
        margin-top: var(--spacing-2xl);
        grid-template-columns: repeat(2, 1fr);
      }

      .trends-grid {
        gap: var(--spacing-xl);
        display: grid;
        margin-top: var(--spacing-2xl);
        grid-template-columns: repeat(2, 1fr);
      }

      .alert-info {
        gap: var(--spacing-lg);
        display: flex;
        align-items: center;
      }

      .table-container {
        border: 1px solid var(--color-border);
        margin-top: var(--spacing-2xl);
        overflow-x: auto;
        border-radius: var(--border-radius-md);
      }

      .timeline-container {
        position: relative;
        margin-top: var(--spacing-2xl);
        padding-left: var(--spacing-xl);
      }

      .actions-grid {
        gap: var(--spacing-xl);
        display: grid;
        margin-top: var(--spacing-2xl);
        grid-template-columns: repeat(2, 1fr);
      }

      .live-snapshot-meta {
        gap: var(--spacing-xs);
        color: var(--color-on-surface-secondary);
        display: flex;
        font-size: var(--font-size-sm);
        margin-top: var(--spacing-lg);
        flex-direction: column;
      }

      .readout-card {
        gap: var(--spacing-xl);
        border: 1px solid var(--color-border);
        display: flex;
        padding: var(--spacing-xl);
        background: var(--color-surface-elevated);
        transition: transform 0.3s ease;
        align-items: center;
        border-radius: var(--border-radius-lg);
      }

      .stat-card {
        gap: var(--spacing-sm);
        border: 1px solid var(--color-border);
        display: flex;
        padding: var(--spacing-xl);
        background: var(--color-surface-elevated);
        border-radius: var(--border-radius-md);
        flex-direction: column;
      }

      .trend-module {
        border: 1px solid var(--color-border);
        padding: var(--spacing-xl);
        background: var(--color-surface);
        border-radius: var(--border-radius-md);
      }

      .alert-icon-box {
        color: #e74c3c;
        flex-shrink: 0;
      }

      .health-table {
        width: 100%;
        text-align: left;
        border-collapse: collapse;
      }

      .timeline-item {
        position: relative;
        padding-bottom: var(--spacing-2xl);
      }

      .action-btn {
        gap: var(--spacing-md);
        border: 1px solid var(--color-border);
        cursor: pointer;
        display: flex;
        padding: var(--spacing-2xl);
        background: var(--color-surface-elevated);
        transition: all 0.3s ease;
        align-items: center;
        border-radius: var(--border-radius-lg);
        flex-direction: column;
        justify-content: center;
      }

      .readout-icon-wrapper {
        color: var(--color-primary);
        width: 64px;
        height: 64px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 20%, transparent);
        align-items: center;
        border-radius: var(--border-radius-md);
        justify-content: center;
      }

      .readout-data {
        display: flex;
        flex-direction: column;
      }

      .stat-header {
        color: var(--color-on-surface-secondary);
        display: flex;
        align-items: center;
        justify-content: space-between;
      }

      .stat-value {
        color: var(--color-primary);
        font-size: var(--font-size-2xl);
        font-weight: var(--font-weight-heading);
      }

      .stat-trend {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-xs);
      }

      .trend-up {
        color: #2ecc71;
      }

      .trend-visual {
        height: 120px;
        margin: var(--spacing-md) 0;
        overflow: hidden;
        position: relative;
        background: color-mix(in srgb, var(--color-neutral) 30%, transparent);
        border-radius: var(--border-radius-sm);
      }

      .timeline-marker {
        top: 0;
        left: -25px;
        width: 12px;
        border: 2px solid var(--color-surface);
        height: 12px;
        position: absolute;
        background: var(--color-primary);
        border-radius: 50%;
      }

      .action-icon {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .action-label {
        font-weight: var(--font-weight-medium);
      }

      .readout-label {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-sm);
      }

      .readout-value {
        font-size: var(--font-size-3xl);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
      }

      .sparkline {
        left: 0;
        width: 100%;
        bottom: 0;
        height: 100%;
        position: absolute;
        background: linear-gradient(
          0deg,
          color-mix(in srgb, var(--color-primary) 20%, transparent),
          transparent
        );
        mask-image: linear-gradient(
          90deg,
          transparent,
          black 20%,
          black 80%,
          transparent
        );
      }

      .spark-water {
        border-bottom: 2px solid var(--color-primary);
      }

      .spark-rssi {
        border-bottom: 2px solid var(--color-secondary);
      }

      .spark-temp {
        border-bottom: 2px solid var(--color-accent);
      }

      .spark-packet {
        border-bottom: 2px solid #2ecc71;
      }

      .event-time {
        color: var(--color-primary);
        font-size: var(--font-size-xs);
        font-weight: var(--font-weight-medium);
      }

      .event-title {
        margin: var(--spacing-xs) 0;
        font-size: var(--font-size-lg);
        font-weight: var(--font-weight-heading);
      }

      .status-badge {
        padding: var(--spacing-xs) var(--spacing-sm);
        font-size: var(--font-size-xs);
        font-weight: var(--font-weight-medium);
        border-radius: var(--border-radius-full);
      }

      .online {
        color: #2ecc71;
        background: color-mix(in srgb, #2ecc71 20%, transparent);
      }

      .warning {
        color: #f39c12;
        background: color-mix(in srgb, #f39c12 20%, transparent);
      }

      .offline {
        color: #e74c3c;
        background: color-mix(in srgb, #e74c3c 20%, transparent);
      }

      .readout-card:hover {
        transform: translateX(10px);
        border-color: var(--color-primary);
      }

      .readout-value small {
        opacity: 0.7;
        font-size: var(--font-size-lg);
        margin-left: var(--spacing-xs);
      }

      .health-table th {
        padding: var(--spacing-lg);
        background: var(--color-surface-elevated);
        font-weight: var(--font-weight-medium);
        border-bottom: 2px solid var(--color-border);
      }

      .health-table td {
        padding: var(--spacing-lg);
        border-bottom: 1px solid var(--color-border);
      }

      .timeline-container::before {
        top: 0;
        left: 0;
        width: 2px;
        bottom: 0;
        content: "";
        position: absolute;
        background: var(--color-border);
      }

      .action-btn:hover {
        color: var(--color-on-primary);
        transform: translateY(-5px);
        background: var(--color-primary);
        border-color: var(--color-primary);
      }

      .action-btn:hover .action-icon {
        color: var(--color-primary);
        background: var(--color-on-primary);
      }

      .Content {
        font-size: 16px;
        font-family: Inter;
        font-weight: 400;
        line-height: 1.15;
        text-transform: none;
        text-decoration: none;
      }

      .BodyFont {
        font-size: 1rem;
        font-family: Nunito Sans;
        font-weight: 400;
        line-height: 1.6;
        letter-spacing: 0.01em;
      }

      .Headings {
        font-size: 2em;
        font-family: Rubik;
        font-weight: 700;
        line-height: 1.2;
        letter-spacing: 0.02em;
      }

      @media (max-width: 991px) {
        .thq-grid-4 {
          grid-template-columns: 1fr 1fr 1fr;
        }
        .navigation-links-desktop {
          gap: var(--spacing-lg);
        }
        .footer-grid {
          gap: var(--spacing-3xl);
          grid-template-columns: 1fr 1fr;
        }
        .footer-brand-col {
          text-align: center;
          align-items: center;
          grid-column: span 2;
        }
        .footer-description {
          max-width: 600px;
        }
        .live-snapshot-container {
          text-align: center;
          flex-direction: column;
        }
      }

      @media (max-width: 767px) {
        .thq-section-padding {
          padding: var(--dl-layout-space-threeunits);
        }
        .thq-flex-column {
          gap: var(--dl-layout-space-oneandhalfunits);
        }
        .thq-flex-row {
          gap: var(--dl-layout-space-oneandhalfunits);
        }
        .thq-grid-6 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          grid-template-columns: 1fr 1fr 1fr;
        }
        .thq-grid-5 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          grid-template-columns: 1fr 1fr 1fr;
        }
        .thq-card {
          padding: var(--dl-layout-space-oneandhalfunits);
        }
        .thq-grid-3 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          grid-template-columns: 1fr 1fr;
        }
        .thq-grid-4 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          flex-direction: row;
          grid-template-columns: 1fr 1fr;
        }
        .thq-grid-2 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          grid-template-columns: 1fr;
        }
        .thq-img-scale {
          width: 100%;
        }
        .navigation-links-desktop {
          display: none;
        }
        .navigation-toggle {
          display: flex;
        }
        .footer-root {
          padding: var(--spacing-3xl) 0 var(--spacing-xl);
        }
        .footer-grid {
          gap: var(--spacing-2xl);
          grid-template-columns: 1fr;
        }
        .footer-brand-col {
          grid-column: span 1;
        }
        .footer-legal-wrap {
          text-align: center;
          flex-direction: column;
        }
        .alert-banner {
          text-align: center;
          flex-direction: column;
        }
        .quick-stats-grid {
          grid-template-columns: 1fr;
        }
        .trends-grid {
          grid-template-columns: 1fr;
        }
        .actions-grid {
          grid-template-columns: 1fr;
        }
        .readout-card {
          text-align: center;
          flex-direction: column;
        }
      }

      @media (max-width: 479px) {
        .thq-section-padding {
          padding: var(--dl-layout-space-oneandhalfunits);
        }
        .thq-flex-column {
          gap: var(--dl-layout-space-unit);
        }
        .thq-flex-row {
          gap: var(--dl-layout-space-unit);
        }
        .thq-grid-6 {
          grid-gap: var(--dl-layout-space-unit);
          grid-template-columns: 1fr 1fr;
        }
        .thq-grid-5 {
          grid-gap: var(--dl-layout-space-unit);
          grid-template-columns: 1fr 1fr;
        }
        .thq-grid-3 {
          grid-gap: var(--dl-layout-space-unit);
          align-items: center;
          grid-template-columns: 1fr;
        }
        .thq-grid-4 {
          grid-gap: var(--dl-layout-space-unit);
          align-items: center;
          flex-direction: column;
          grid-template-columns: 1fr;
        }
        .thq-grid-2 {
          grid-gap: var(--dl-layout-space-unit);
        }
        .thq-grid-auto-300 {
          grid-template-columns: 1fr;
        }
        .footer-container {
          padding: 0 var(--spacing-lg);
        }
        .footer-logo-wrap {
          flex-direction: column;
        }
        .home-hero-title {
          font-size: var(--font-size-3xl);
        }
        .readout-value {
          font-size: var(--font-size-2xl);
        }
      }

      /* footer.css */
      .footer-container1 {
        display: contents;
      }

      .footer-container2 {
        display: none;
      }

      .footer-container3 {
        display: contents;
      }

      .footer-container4 {
        display: none;
      }

      .footer-container5 {
        display: contents;
      }

      /* navigation.css */
      .navigation-container1 {
        display: contents;
      }

      .navigation-container2 {
        display: none;
      }

      .navigation-container3 {
        display: contents;
      }

      .navigation-container4 {
        display: none;
      }

      .navigation-container5 {
        display: contents;
      }
    </style>
  </head>
  <body>
    <div>
      <div class="home-container1">
        <navigation-wrapper class="navigation-wrapper">
          <!--Navigation component-->
          <div class="navigation-container1">
            <nav class="navigation-container">
              <div class="navigation-wrapper">
                <a href="index.html">
                  <div aria-label="AquaSignal Home" class="navigation-brand">
                    <div class="navigation-logo-icon">
                      <svg
                        xmlns="http://www.w3.org/2000/svg"
                        width="24"
                        height="24"
                        viewBox="0 0 24 24"
                      >
                        <g
                          fill="none"
                          stroke="currentColor"
                          stroke-linecap="round"
                          stroke-linejoin="round"
                          stroke-width="2"
                        >
                          <path
                            d="M5.116 4.104A1 1 0 0 1 6.11 3h11.78a1 1 0 0 1 .994 1.105L17.19 20.21A2 2 0 0 1 15.2 22H8.8a2 2 0 0 1-2-1.79z"
                          ></path>
                          <path d="M6 12a5 5 0 0 1 6 0a5 5 0 0 0 6 0"></path>
                        </g>
                      </svg>
                    </div>
                    <span class="section-title">Water Level</span>
                  </div>
                </a>
                <div class="navigation-links-desktop">
                  <a href="/settings">
                    <div class="navigation-link"><span>Settings</span></div>
                  </a>
                </div>
                <button
                  id="navToggle"
                  aria-label="Toggle Menu"
                  aria-expanded="false"
                  class="navigation-toggle"
                >
                  <svg
                    xmlns="http://www.w3.org/2000/svg"
                    width="24"
                    height="24"
                    viewBox="0 0 24 24"
                    class="icon-menu"
                  >
                    <path
                      fill="none"
                      stroke="currentColor"
                      stroke-linecap="round"
                      stroke-linejoin="round"
                      stroke-width="2"
                      d="M4 6h16M4 12h16M4 18h16"
                    ></path>
                  </svg>
                </button>
              </div>
            </nav>
            <div id="mobileMenu" class="navigation-mobile-overlay">
              <div class="navigation-mobile-header">
                <a href="index.html">
                  <div aria-label="AquaSignal Home" class="navigation-brand">
                    <div class="navigation-logo-icon">
                      <svg
                        xmlns="http://www.w3.org/2000/svg"
                        width="24"
                        height="24"
                        viewBox="0 0 24 24"
                      >
                        <g
                          fill="none"
                          stroke="currentColor"
                          stroke-linecap="round"
                          stroke-linejoin="round"
                          stroke-width="2"
                        >
                          <path
                            d="M5.116 4.104A1 1 0 0 1 6.11 3h11.78a1 1 0 0 1 .994 1.105L17.19 20.21A2 2 0 0 1 15.2 22H8.8a2 2 0 0 1-2-1.79z"
                          ></path>
                          <path d="M6 12a5 5 0 0 1 6 0a5 5 0 0 0 6 0"></path>
                        </g>
                      </svg>
                    </div>
                    <span class="section-title">Water Level</span>
                  </div>
                </a>
                <button
                  id="navClose"
                  aria-label="Close Menu"
                  class="navigation-close"
                >
                  <svg
                    xmlns="http://www.w3.org/2000/svg"
                    width="24"
                    height="24"
                    viewBox="0 0 24 24"
                  >
                    <path
                      fill="none"
                      stroke="currentColor"
                      stroke-linecap="round"
                      stroke-linejoin="round"
                      stroke-width="2"
                      d="M18 6L6 18M6 6l12 12"
                    ></path>
                  </svg>
                </button>
              </div>
              <div class="navigation-mobile-content">
                <div class="navigation-mobile-links">
                  <a href="/settings">
                    <div class="navigation-mobile-link">
                      <span>Settings</span>
                    </div>
                  </a>
                </div>
                <div class="navigation-mobile-footer">
                  <p class="section-content">Real-time water level</p>
                </div>
              </div>
            </div>
            <div class="navigation-container2">
              <div class="navigation-container3">
                <style>
                  @media (prefers-reduced-motion: reduce) {
                    .navigation-mobile-overlay {
                      transition: opacity 0.3s ease;
                      transform: none;
                      opacity: 0;
                    }
                    .navigation-mobile-overlay.is-open {
                      opacity: 1;
                    }
                  }
                </style>
              </div>
            </div>
            <div class="navigation-container4">
              <div class="navigation-container5">
                <script defer="" data-name="navigation-logic">
                  document.addEventListener("DOMContentLoaded", function () {
                    (function () {
                      const navToggle = document.getElementById("navToggle");
                      const navClose = document.getElementById("navClose");
                      const mobileMenu = document.getElementById("mobileMenu");
                      const body = document.body;

                      function openMenu() {
                        mobileMenu.classList.add("is-open");
                        navToggle.setAttribute("aria-expanded", "true");
                        body.style.overflow = "hidden";
                      }

                      function closeMenu() {
                        mobileMenu.classList.remove("is-open");
                        navToggle.setAttribute("aria-expanded", "false");
                        body.style.overflow = "";
                      }

                      navToggle.addEventListener("click", openMenu);
                      navClose.addEventListener("click", closeMenu);

                      // Close menu when clicking on a link
                      const mobileLinks = document.querySelectorAll(
                        ".navigation-mobile-link",
                      );
                      mobileLinks.forEach((link) => {
                        link.addEventListener("click", closeMenu);
                      });

                      // Close menu on ESC key
                      document.addEventListener("keydown", (e) => {
                        if (
                          e.key === "Escape" &&
                          mobileMenu.classList.contains("is-open")
                        ) {
                          closeMenu();
                        }
                      });
                    })();
                  });
                </script>
              </div>
            </div>
          </div>
        </navigation-wrapper>

        <main class="aqua-dashboard">
          <section class="live-snapshot">
            <div class="live-snapshot-container">
              <div class="live-snapshot-content">
                <h1 class="home-hero-title hero-title">Live Monitoring</h1>
                <p class="hero-subtitle">
                  Real-time monitoring water resource management.
                </p>
                <div class="live-snapshot-meta">
                  <span class="meta-item">
                    <span>Device ID:</span>
                    <span class="home-text11" id="DeviceId">01</span>
                  </span>
                  <span class="meta-item">
                    <span>Location:</span>
                    <span class="home-text11" id="LocationValue">-</span>
                  </span>
                  <span class="meta-item">
                    <span>Last Sent:</span>
                    <span id="lastSentValue" datetime="2026-10-24T14:30"
                      >Oct 24, 14:30:22</span
                    >
                  </span>
                </div>
              </div>
              <div class="live-snapshot-readout">
                <div class="readout-card water-level">
                  <div class="readout-icon-wrapper">
                    <svg
                      xmlns="http://www.w3.org/2000/svg"
                      width="24"
                      height="24"
                      viewBox="0 0 24 24"
                    >
                      <path
                        fill="none"
                        stroke="currentColor"
                        stroke-linecap="round"
                        stroke-linejoin="round"
                        stroke-width="2"
                        d="M12 22a7 7 0 0 0 7-7c0-2-1-3.9-3-5.5s-3.5-4-4-6.5c-.5 2.5-2 4.9-4 6.5S5 13 5 15a7 7 0 0 0 7 7"
                      ></path>
                    </svg>
                  </div>
                  <div class="readout-data">
                    <span class="readout-label">Water Level</span>
                    <span class="readout-value">
                      <span id="WaterLevelValue" id="WaterLevelValue"
                        >299.9</span
                      >
                      <span>m</span>
                    </span>
                  </div>
                </div>
                <div class="readout-card signal-strength">
                  <div
                    id="signalBars"
                    class="signal-bars-container readout-icon-wrapper"
                  >
                    <div class="bar bar-1"></div>
                    <div class="bar bar-2"></div>
                    <div class="bar bar-3"></div>
                  </div>
                  <div class="readout-data">
                    <span class="readout-label">Signal Strength</span>
                    <span class="readout-value">
                      <span id="SignalValue">-68</span>
                      <span>dBm</span>
                    </span>
                  </div>
                </div>
              </div>
            </div>
          </section>
        </main>

        <footer-wrapper class="footer-wrapper">
          <!--Footer component-->
          <div class="footer-container1">
            <footer class="footer-root">
              <div class="footer-glass-overlay"></div>
              <div class="footer-container">
                <div class="footer-grid">
                  <div class="footer-column footer-brand-col">
                    <div class="footer-logo-wrap">
                      <div class="footer-logo-icon">
                        <svg
                          xmlns="http://www.w3.org/2000/svg"
                          width="24"
                          height="24"
                          viewBox="0 0 24 24"
                        >
                          <path
                            fill="none"
                            stroke="currentColor"
                            stroke-linecap="round"
                            stroke-linejoin="round"
                            stroke-width="2"
                            d="M12 22a7 7 0 0 0 7-7c0-2-1-3.9-3-5.5s-3.5-4-4-6.5c-.5 2.5-2 4.9-4 6.5S5 13 5 15a7 7 0 0 0 7 7"
                          ></path>
                        </svg>
                      </div>
                      <span class="footer-brand-name">Water Level</span>
                    </div>
                    <p class="footer-description section-content">
                      IO dashboard for real-time water level monitoring.
                    </p>
                  </div>
                  <div class="footer-column">
                    <h2 class="footer-col-title section-subtitle">
                      Core Metrics
                    </h2>
                    <ul class="footer-nav-list">
                      <li class="footer-nav-item">
                        <div class="footer-nav-icon">
                          <svg
                            xmlns="http://www.w3.org/2000/svg"
                            width="24"
                            height="24"
                            viewBox="0 0 24 24"
                          >
                            <path
                              fill="none"
                              stroke="currentColor"
                              stroke-linecap="round"
                              stroke-linejoin="round"
                              stroke-width="2"
                              d="M12 22a7 7 0 0 0 7-7c0-2-1-3.9-3-5.5s-3.5-4-4-6.5c-.5 2.5-2 4.9-4 6.5S5 13 5 15a7 7 0 0 0 7 7"
                            ></path>
                          </svg>
                        </div>
                        <span class="section-content">Water Level (m)</span>
                      </li>
                      <li class="footer-nav-item">
                        <div class="footer-nav-icon">
                          <svg
                            xmlns="http://www.w3.org/2000/svg"
                            width="24"
                            height="24"
                            viewBox="0 0 24 24"
                          >
                            <path
                              fill="none"
                              stroke="currentColor"
                              stroke-linecap="round"
                              stroke-linejoin="round"
                              stroke-width="2"
                              d="M2 20h.01M7 20v-4m5 4v-8m5 8V8m5-4v16"
                            ></path>
                          </svg>
                        </div>
                        <span class="section-content">
                          RSSI Signal Strength
                        </span>
                      </li>
                    </ul>
                  </div>
                </div>
                <div class="footer-bottom">
                  <div class="footer-divider"></div>
                  <div class="footer-legal-wrap">
                    <p class="footer-copyright section-content">
                      &amp;2026 Water Level Monitoring. All rights reserved.
                    </p>
                  </div>
                </div>
              </div>
            </footer>
          </div>
        </footer-wrapper>
      </div>
    </div>

    <script>
      function updateRealtimeData() {
        fetch("/api/realtime")
          .then((response) => response.json())
          .then((data) => {
            const waterLevel = data.water_level;
            const signal = data.rssi;
            const deviceId = data.device_id;
            const location = data.location;

            const wlEl = document.getElementById("WaterLevelValue");
            const signalEl = document.getElementById("SignalValue");
            const incomingRssi = data.rssi; // Misal data RSSI dari perangkat
            updateRssiBars(incomingRssi);
            document.getElementById("DeviceId").textContent = deviceId;
            const locEl = document.getElementById("LocationValue");
            if (locEl) {
              locEl.textContent = location && location.length ? location : "-";
            }

            if (wlEl) {
              wlEl.textContent = waterLevel.toFixed(1);
            }

            if (signalEl) {
              signalEl.textContent = signal;
            }

            const lsEl = document.getElementById("lastSentValue");

            if (lsEl) {
              if (data.last_sent_str && data.last_sent_str.length > 0) {
                lsEl.textContent = data.last_sent_str;
              } else if (data.last_sent && data.last_sent > 0) {
                const ut = data.last_sent * 1000;
                const dLocal = new Date(ut);
                const localStr = dLocal.toLocaleString();
                lsEl.textContent = localStr;
              } else {
                lsEl.textContent = "Never";
              }
            }
          })
          .catch((error) => {
            console.error("Error fetching realtime data:", error);
          });
      }

      // Fungsi untuk memperbarui tampilan bar sinyal
      function updateRssiBars(rssiValue) {
        const barsContainer = document.getElementById("signalBars");
        if (!barsContainer) return; // Keluar jika elemen tidak ditemukan

        const bar1 = barsContainer.querySelector(".bar-1");
        const bar2 = barsContainer.querySelector(".bar-2");
        const bar3 = barsContainer.querySelector(".bar-3");

        // Hapus kelas warna dan aktif sebelumnya
        [bar1, bar2, bar3].forEach((bar) => {
          bar.classList.remove(
            "bar-red",
            "bar-orange",
            "bar-green",
            "active-bar",
          );
        });

        // Handle No Signal (0), Unknown (99), atau nilai di luar range
        if (rssiValue === 0 || rssiValue === 99 || rssiValue < 10) {
          // Biarkan semua bar tidak berwarna/abu-abu (atau Anda bisa set 1 bar merah)
          // Untuk 0 bar:
          // bar1.classList.add('bar-red', 'active-bar'); // Jika ingin 1 bar merah untuk sinyal sangat buruk
          // Jika 0 bar: tidak perlu ditambahkan kelas aktif/warna
          return;
        }

        // Level 1: Low Signal (10 - 19)
        if (rssiValue >= 10 && rssiValue < 20) {
          bar1.classList.add("bar-red", "active-bar");
        }
        // Level 2: Medium Signal (20 - 24)
        else if (rssiValue >= 20 && rssiValue < 25) {
          bar1.classList.add("bar-orange", "active-bar");
          bar2.classList.add("bar-orange", "active-bar");
        }
        // Level 3: High Signal (25 - 31)
        else if (rssiValue >= 25 && rssiValue <= 31) {
          bar1.classList.add("bar-green", "active-bar");
          bar2.classList.add("bar-green", "active-bar");
          bar3.classList.add("bar-green", "active-bar");
        }

        // Untuk nilai di luar 0-31 (misalnya error) tetap 0 bar atau 'Never'

        // CONTOH PENGGUNAAN (Anda harus memanggil fungsi ini saat data baru tiba)
        // const incomingRssi = data.rssi; // Misal data RSSI dari perangkat
        // updateRssiBars(incomingRssi);

        // dan jangan lupa update nilai angka di #rssiValue
        // document.getElementById('rssiValue').textContent = incomingRssi;
      }

      function initializePage() {
        updateRealtimeData();
      }

      // Initialize on page load
      window.onload = initializePage;

      // Handle browser back/forward navigation
      window.addEventListener("pageshow", function (event) {
        if (event.persisted) {
          initializePage();
        }
      });

      // Update data every second
      setInterval(updateRealtimeData, 1000);
    </script>
  </body>
</html>
)rawliteral";

const char setting_page_html[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang="en">
  <head>
    <title>Water Level Monitoring</title>
    <meta property="og:title" content="Water Level Monitoring" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta charset="utf-8" />
    <meta property="twitter:card" content="summary_large_image" />

    <style data-tag="reset-style-sheet">
      html {
        line-height: 1.15;
      }
      body {
        margin: 0;
      }
      * {
        box-sizing: border-box;
        border-width: 0;
        border-style: solid;
        -webkit-font-smoothing: antialiased;
      }
      p,
      li,
      ul,
      pre,
      div,
      h1,
      h2,
      h3,
      h4,
      h5,
      h6,
      figure,
      blockquote,
      figcaption {
        margin: 0;
        padding: 0;
      }
      button {
        background-color: transparent;
      }
      button,
      input,
      optgroup,
      select,
      textarea {
        font-family: inherit;
        font-size: 100%;
        line-height: 1.15;
        margin: 0;
      }
      button,
      select {
        text-transform: none;
      }
      button,
      [type="button"],
      [type="reset"],
      [type="submit"] {
        -webkit-appearance: button;
        color: inherit;
      }
      button::-moz-focus-inner,
      [type="button"]::-moz-focus-inner,
      [type="reset"]::-moz-focus-inner,
      [type="submit"]::-moz-focus-inner {
        border-style: none;
        padding: 0;
      }
      button:-moz-focus,
      [type="button"]:-moz-focus,
      [type="reset"]:-moz-focus,
      [type="submit"]:-moz-focus {
        outline: 1px dotted ButtonText;
      }
      a {
        color: inherit;
        text-decoration: inherit;
      }
      pre {
        white-space: normal;
      }
      input {
        padding: 2px 4px;
      }
      img {
        display: block;
      }
      details {
        display: block;
        margin: 0;
        padding: 0;
      }
      summary::-webkit-details-marker {
        display: none;
      }
      [data-thq="accordion"] [data-thq="accordion-content"] {
        max-height: 0;
        overflow: hidden;
        transition: max-height 0.3s ease-in-out;
        padding: 0;
      }
      [data-thq="accordion"]
        details[data-thq="accordion-trigger"][open]
        + [data-thq="accordion-content"] {
        max-height: 1000vh;
      }
      details[data-thq="accordion-trigger"][open]
        summary
        [data-thq="accordion-icon"] {
        transform: rotate(180deg);
      }
      html {
        scroll-behavior: smooth;
      }
    </style>
    <style data-tag="default-style-sheet">
      html {
        font-family: "Nunito Sans";
        font-size: 1rem;
      }

      body {
        font-weight: 400;
        font-style: normal;
        text-decoration: undefined;
        text-transform: undefined;
        letter-spacing: 0.01em;
        line-height: 1.6;
        color: var(--color-on-surface);
        background: var(--color-surface);

        fill: var(--color-on-surface);
      }
    </style>

    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Inter:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&amp;display=swap"
      data-tag="font"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=STIX+Two+Text:ital,wght@0,400;0,500;0,600;0,700;1,400;1,500;1,600;1,700&amp;display=swap"
      data-tag="font"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Noto+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&amp;display=swap"
      data-tag="font"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Nunito+Sans:ital,wght@0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&amp;display=swap"
      data-tag="font"
    />
    <link
      rel="stylesheet"
      href="https://fonts.googleapis.com/css2?family=Rubik:ital,wght@0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,300;1,400;1,500;1,600;1,700;1,800;1,900&amp;display=swap"
      data-tag="font"
    />

    <style>
      /* index.css */
      .dashboard-settings {
        border: 1px solid var(--color-border);
        padding: var(--spacing-2xl) var(--spacing-xl);
        border-radius: var(--border-radius-xl);
        background-color: var(--color-surface-elevated);
      }

      .navigation-wrapper {
        display: contents;
      }

      .navigation-container1 {
        display: contents;
      }

      .navigation-container2 {
        display: none;
      }

      .navigation-container3 {
        display: contents;
      }

      .navigation-container4 {
        display: none;
      }

      .navigation-container5 {
        display: contents;
      }

      .footer-wrapper {
        display: contents;
      }

      .footer-container1 {
        display: contents;
      }

      .footer-container2 {
        display: none;
      }

      .footer-container3 {
        display: contents;
      }

      .footer-container4 {
        display: none;
      }

      .footer-container5 {
        display: contents;
      }

      .home-container1 {
        width: 100%;
        display: block;
        min-height: 100vh;
      }

      .home-text11 {
        font-weight: 700;
      }

      .home-thq-action-icon-elm1 {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .home-thq-action-label-elm1 {
        font-weight: var(--font-weight-medium);
      }

      .home-thq-action-icon-elm2 {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .home-thq-action-label-elm2 {
        font-weight: var(--font-weight-medium);
      }

      .home-thq-action-icon-elm3 {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .home-thq-action-label-elm3 {
        font-weight: var(--font-weight-medium);
      }

      .home-thq-action-icon-elm4 {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .home-thq-action-label-elm4 {
        font-weight: var(--font-weight-medium);
      }

      .home-container2 {
        display: none;
      }

      .home-container3 {
        display: contents;
      }

      .home-container4 {
        right: 50px;
        border: 1px solid #ffffff5c;
        bottom: 30px;
        display: flex;
        z-index: 22;
        position: fixed;
        box-shadow: 5px 5px 10px 0px rgba(31, 31, 31, 0.4);
        min-height: auto;
        align-items: center;
        padding-top: 8px;
        padding-left: 12px;
        border-radius: 8px;
        padding-right: 12px;
        padding-bottom: 8px;
        backdrop-filter: blur(6px);
        background-color: rgba(41, 41, 41, 0.41);
      }

      .home-icon37 {
        width: 24px;
        margin-right: 4px;
      }

      .home-text40 {
        color: white;
        font-size: 13px;
        font-style: normal;
        font-weight: 500;
        line-height: 24px;
      }

      /* style.css */
      :root {
        --spacing-lg: 1rem;
        --spacing-md: 0.75rem;
        --spacing-sm: 0.5rem;
        --spacing-xl: 1.5rem;
        --spacing-xs: 0.25rem;
        --color-scrim: color-mix(in oklab, #ffffff 70%, transparent);
        --spacing-2xl: 2rem;
        --spacing-3xl: 3rem;
        --spacing-4xl: 4rem;
        --color-accent: #a8ff00;
        --color-border: #303033;
        --font-size-lg: clamp(1.1rem, 1rem + 0.5vw, 1.25rem);
        --font-size-sm: clamp(0.85rem, 0.75rem + 0.25vw, 0.95rem);
        --font-size-xl: clamp(1.4rem, 1.2rem + 0.9vw, 1.6rem);
        --font-size-xs: clamp(0.65rem, 0.55rem + 0.2vw, 0.8rem);
        --color-neutral: #303033;
        --color-outline: #00c2a8;
        --color-overlay: color-mix(in oklab, #ffffff 40%, transparent);
        --color-primary: #007aff;
        --color-surface: #121212;
        --divider-value: 0px none var(--color-border);
        --font-size-2xl: clamp(1.8rem, 1.6rem + 1.1vw, 2rem);
        --font-size-3xl: clamp(2.2rem, 2rem + 1.6vw, 2.8rem);
        --font-size-4xl: clamp(3rem, 2.6rem + 2.2vw, 4.2rem);
        --font-size-base: 1rem;
        --shadow-level-1: 0 4px 12px rgba(100, 50, 200, 0.15);
        --shadow-level-2: 0 12px 32px rgba(100, 50, 200, 0.2);
        --shadow-level-3: 0 24px 60px rgba(100, 50, 200, 0.25);
        --color-backplate: color-mix(in oklab, #ffffff 60%, transparent);
        --color-on-accent: #000000;
        --color-secondary: #00b89a;
        --border-radius-lg: 24px;
        --border-radius-md: 16px;
        --border-radius-sm: 8px;
        --border-radius-xl: 40px;
        --color-on-primary: #ffffff;
        --color-on-surface: #f6fbff;
        --font-family-body:
          "Nunito Sans", system-ui, -apple-system, "Segoe UI", Roboto,
          "Helvetica Neue", Arial;
        --font-weight-body: 400;
        --line-height-body: 1.6;
        --content-max-width: 84rem;
        --border-radius-card: 24px;
        --border-radius-full: 9999px;
        --border-radius-none: 0px;
        --color-on-secondary: #ffffff;
        --font-style-heading: normal;
        --font-weight-medium: 600;
        --font-family-heading:
          "Rubik", system-ui, -apple-system, "Segoe UI", Roboto,
          "Helvetica Neue", Arial;
        --font-weight-heading: 700;
        --letter-spacing-body: 0.01em;
        --line-height-heading: 1.25;
        --dl-layout-size-large: 144px;
        --dl-layout-size-small: 48px;
        --dl-layout-space-unit: 16px;
        --border-radius-control: 16px;
        --dl-layout-size-medium: 96px;
        --dl-layout-size-xlarge: 192px;
        --dl-layout-size-xsmall: 16px;
        --font-style-subheading: italic;
        --color-surface-elevated: color-mix(in oklab, #121212 92%, #00b89a);
        --dl-color-theme-accent1: #ffffff;
        --dl-color-theme-accent2: #f5d1b0;
        --dl-layout-radius-round: 50%;
        --dl-layout-size-xxlarge: 288px;
        --letter-spacing-heading: 0.02em;
        --text-transform-heading: none;
        --dl-color-theme-primary1: #bf4408;
        --dl-color-theme-primary2: #e65103;
        --dl-layout-size-maxwidth: 1400px;
        --dl-layout-radius-radius2: 2px;
        --dl-layout-radius-radius4: 4px;
        --dl-layout-radius-radius8: 8px;
        --dl-layout-space-halfunit: 8px;
        --dl-layout-space-sixunits: 96px;
        --dl-layout-space-twounits: 32px;
        --dl-color-theme-secondary1: #ffffff;
        --dl-color-theme-secondary2: #fbf1eb;
        --dl-layout-space-fiveunits: 80px;
        --dl-layout-space-fourunits: 64px;
        --color-on-surface-secondary: #b9c4ce;
        --dl-layout-space-threeunits: 48px;
        --dl-color-theme-neutral-dark: #191818;
        --dl-layout-radius-cardradius: 8px;
        --dl-color-theme-neutral-light: #fbfaf9;
        --dl-layout-radius-imageradius: 8px;
        --dl-layout-radius-inputradius: 24px;
        --dl-layout-radius-buttonradius: 24px;
        --dl-layout-space-oneandhalfunits: 24px;
      }

      .button {
        color: var(--dl-color-theme-neutral-dark);
        display: inline-block;
        padding: 0.5rem 1rem;
        border-color: var(--dl-color-theme-neutral-dark);
        border-width: 1px;
        border-radius: 4px;
        background-color: var(--dl-color-theme-neutral-light);
      }

      .input {
        color: var(--dl-color-theme-neutral-dark);
        cursor: auto;
        padding: 0.5rem 1rem;
        border-color: var(--dl-color-theme-neutral-dark);
        border-width: 1px;
        border-radius: 4px;
        background-color: var(--dl-color-theme-neutral-light);
      }

      .textarea {
        color: var(--dl-color-theme-neutral-dark);
        cursor: auto;
        padding: 0.5rem;
        border-color: var(--dl-color-theme-neutral-dark);
        border-width: 1px;
        border-radius: 4px;
        background-color: var(--dl-color-theme-neutral-light);
      }

      .list {
        width: 100%;
        margin: 1em 0px 1em 0px;
        display: block;
        padding: 0px 0px 0px 1.5rem;
        list-style-type: none;
        list-style-position: outside;
      }

      .list-item {
        display: list-item;
      }

      .teleport-show {
        display: flex !important;
        transform: none !important;
      }

      .thq-input {
        color: var(--dl-color-theme-neutral-dark);
        cursor: auto;
        outline: none;
        padding: 0.5rem 1rem;
        align-self: stretch;
        text-align: center;
        border-color: var(--dl-color-theme-neutral-dark);
        border-width: 1px;
        border-radius: var(--dl-layout-radius-inputradius);
        background-color: var(--dl-color-theme-neutral-light);
      }

      .thq-input:focus {
        outline: 1px solid var(--dl-color-theme-primary1);
      }

      .thq-button-filled {
        gap: var(--dl-layout-space-halfunit);
        fill: var(--dl-color-theme-secondary1);
        color: var(--dl-color-theme-secondary1);
        cursor: pointer;
        display: flex;
        transition: 0.3s;
        align-items: center;
        font-weight: bold;
        padding-top: var(--dl-layout-space-halfunit);
        white-space: nowrap;
        border-color: var(--dl-color-theme-primary1);
        border-width: 1px;
        padding-left: var(--dl-layout-space-oneandhalfunits);
        border-radius: var(--dl-layout-radius-buttonradius);
        padding-right: var(--dl-layout-space-oneandhalfunits);
        padding-bottom: var(--dl-layout-space-halfunit);
        justify-content: center;
        background-color: var(--dl-color-theme-primary1);
      }

      .thq-button-filled:hover {
        fill: var(--dl-color-theme-secondary2);
        color: var(--dl-color-theme-secondary2);
        border-color: var(--dl-color-theme-primary2);
        background-color: var(--dl-color-theme-primary2);
      }

      .thq-button-outline {
        gap: var(--dl-layout-space-halfunit);
        fill: var(--dl-color-theme-primary1);
        color: var(--dl-color-theme-primary1);
        border: 1px solid;
        cursor: pointer;
        display: flex;
        transition: 0.3s;
        align-items: center;
        font-weight: bold;
        padding-top: var(--dl-layout-space-halfunit);
        white-space: nowrap;
        border-color: var(--dl-color-theme-primary1);
        padding-left: var(--dl-layout-space-oneandhalfunits);
        border-radius: var(--dl-layout-radius-buttonradius);
        padding-right: var(--dl-layout-space-oneandhalfunits);
        padding-bottom: var(--dl-layout-space-halfunit);
        justify-content: center;
      }

      .thq-button-outline:hover {
        fill: var(--dl-color-theme-secondary2);
        color: var(--dl-color-theme-secondary2);
        border-color: var(--dl-color-theme-primary2);
        background-color: var(--dl-color-theme-primary2);
      }

      .thq-button-flat {
        gap: var(--dl-layout-space-halfunit);
        fill: var(--dl-color-theme-primary1);
        color: var(--dl-color-theme-primary1);
        cursor: pointer;
        display: flex;
        transition: 0.3s;
        align-items: center;
        font-weight: bold;
        padding-top: var(--dl-layout-space-halfunit);
        white-space: nowrap;
        border-color: transparent;
        border-width: 1px;
        padding-left: var(--dl-layout-space-oneandhalfunits);
        border-radius: var(--dl-layout-radius-buttonradius);
        padding-right: var(--dl-layout-space-oneandhalfunits);
        padding-bottom: var(--dl-layout-space-halfunit);
        justify-content: center;
      }

      .thq-button-flat:hover {
        fill: var(--dl-color-theme-secondary1);
        color: var(--dl-color-theme-secondary1);
        border-color: var(--dl-color-theme-primary2);
        background-color: var(--dl-color-theme-primary2);
      }

      .thq-heading-1 {
        font-size: 48px;
        font-family: STIX Two Text;
        font-weight: 700;
        line-height: 1.5;
      }

      .thq-heading-2 {
        font-size: 35px;
        font-family: STIX Two Text;
        font-weight: 600;
        line-height: 1.5;
      }

      .thq-heading-3 {
        font-size: 26px;
        font-family: STIX Two Text;
        font-weight: 600;
        line-height: 1.5;
      }

      .thq-body-large {
        font-size: 18px;
        font-family: Noto Sans;
        line-height: 1.5;
      }

      .thq-body-small {
        font-size: 16px;
        font-family: Noto Sans;
        line-height: 1.5;
      }

      .thq-team-image-round {
        width: 80px;
        height: 80px;
        object-fit: cover;
        border-radius: 50%;
      }

      .thq-section-padding {
        width: 100%;
        display: flex;
        padding: var(--dl-layout-space-fiveunits);
        position: relative;
        align-items: center;
        flex-direction: column;
      }

      .thq-section-max-width {
        width: 100%;
        max-width: var(--dl-layout-size-maxwidth);
      }

      .thq-img-ratio-1-1 {
        width: 100%;
        object-fit: cover;
        aspect-ratio: 1/1;
        border-radius: var(--dl-layout-radius-imageradius);
      }

      .thq-img-ratio-16-9 {
        width: 100%;
        object-fit: cover;
        aspect-ratio: 16/9;
        border-radius: var(--dl-layout-radius-imageradius);
      }

      .thq-img-ratio-4-3 {
        width: 100%;
        object-fit: cover;
        aspect-ratio: 4/3;
        border-radius: var(--dl-layout-radius-imageradius);
      }

      .thq-img-ratio-4-6 {
        width: 100%;
        object-fit: cover;
        aspect-ratio: 4/6;
        border-radius: var(--dl-layout-radius-imageradius);
      }

      .thq-img-round {
        width: 100%;
        border-radius: var(--dl-layout-radius-round);
      }

      .thq-flex-column {
        gap: var(--dl-layout-space-twounits);
        display: flex;
        overflow: hidden;
        position: relative;
        align-items: center;
        flex-direction: column;
      }

      .thq-flex-row {
        gap: var(--dl-layout-space-twounits);
        display: flex;
        overflow: hidden;
        position: relative;
        align-items: center;
      }

      .thq-grid-6 {
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr 1fr 1fr 1fr 1fr;
      }

      .thq-grid-5 {
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr 1fr 1fr 1fr;
      }

      .thq-card {
        gap: var(--dl-layout-space-oneandhalfunits);
        display: flex;
        padding: var(--dl-layout-space-twounits);
        align-items: stretch;
        border-radius: var(--dl-layout-radius-cardradius);
        flex-direction: column;
      }

      .thq-box-shadow {
        box-shadow: 0px 0px 5px -2px var(--dl-color-theme-neutral-dark);
      }

      .thq-grid-3 {
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr 1fr;
      }

      .thq-grid-4 {
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr 1fr 1fr;
      }

      .thq-grid-2 {
        width: 100%;
        display: grid;
        grid-gap: var(--dl-layout-space-twounits);
        grid-template-columns: 1fr 1fr;
      }

      .thq-checkbox {
        width: var(--dl-layout-size-xsmall);
        height: var(--dl-layout-size-xsmall);
      }

      .thq-select {
        cursor: pointer;
        appearance: none;
        padding-top: var(--dl-layout-space-halfunit);
        padding-left: var(--dl-layout-space-unit);
        border-radius: var(--dl-layout-radius-inputradius);
        padding-right: var(--dl-layout-space-twounits);
        padding-bottom: var(--dl-layout-space-halfunit);
        background-color: var(--dl-color-theme-neutral-light);
        background-image: url("data:image/svg+xml;charset=US-ASCII,%3Csvg width%3D%2220%22 height%3D%2220%22 xmlns%3D%22http%3A//www.w3.org/2000/svg%22 viewBox%3D%220 0 20 20%22 fill%3D%22%23000%22%3E%3Cpath d%3D%22M4.293 7.293a1 1 0 011.414 0L10 11.586l4.293-4.293a1 1 0 111.414 1.414l-5 5a1 1 0 01-1.414 0l-5-5a1 1 0 010-1.414z%22/%3E%3C/svg%3E");
        background-repeat: no-repeat;
        background-position: right 8px center;
      }

      .thq-divider-horizontal {
        width: 100%;
        height: 1px;
        background-color: var(--dl-color-theme-neutral-dark);
      }

      .thq-icon-small {
        width: 24px;
        height: 24px;
      }

      .thq-button-icon {
        fill: var(--dl-color-theme-secondary1);
        padding: 3px;
        transition: 0.3s;
        border-radius: var(--dl-layout-radius-round);
      }

      .thq-button-icon:hover {
        fill: var(--dl-color-theme-secondary2);
      }

      .thq-icon-medium {
        width: var(--dl-layout-size-small);
        height: var(--dl-layout-size-small);
      }

      .thq-icon-x-small {
        width: var(--dl-layout-size-xsmall);
        height: var(--dl-layout-size-xsmall);
      }

      .thq-link {
        cursor: pointer;
        display: inline-block;
        overflow: hidden;
        background: linear-gradient(
          to right,
          var(--dl-color-theme-primary1) 50%,
          var(--dl-color-theme-neutral-dark) 50%
        );
        transition: background-position 300ms ease;
        font-weight: 600;
        background-clip: text;
        background-size: 200% 100%;
        background-position: 100%;
        -webkit-text-fill-color: transparent;
      }

      .thq-link:hover {
        background-position: 0 100%;
      }

      .thq-grid-auto-300 {
        display: grid;
        grid-gap: var(--dl-layout-space-oneandhalfunits);
        grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
      }

      .thq-animated-group-vertical-reverse {
        gap: var(--dl-layout-space-unit);
        width: 100%;
        display: flex;
        animation: scroll-y 20s linear infinite;
        align-items: flex-start;
        flex-direction: column;
        justify-content: space-around;
        animation-direction: reverse;
      }

      .thq-animated-group-horizontal-reverse {
        gap: var(--dl-layout-space-unit);
        display: flex;
        animation: scroll-x 20s linear infinite;
        min-width: 100%;
        align-items: center;
        flex-shrink: 0;
        justify-content: space-around;
        animation-direction: reverse;
      }

      .thq-animated-group-vertical {
        gap: var(--dl-layout-space-unit);
        width: 100%;
        display: flex;
        animation: scroll-y 20s linear infinite;
        align-items: flex-start;
        flex-direction: column;
        justify-content: space-around;
      }

      .thq-animated-group-horizontal {
        gap: var(--dl-layout-space-unit);
        display: flex;
        animation: scroll-x 20s linear infinite;
        min-width: 100%;
        align-items: center;
        flex-shrink: 0;
        justify-content: space-around;
      }

      .thq-animated-group-container-vertical {
        gap: var(--dl-layout-space-unit);
        display: flex;
        overflow: hidden;
        flex-direction: column;
      }

      .thq-animated-group-container-horizontal {
        gap: var(--dl-layout-space-unit);
        display: flex;
        overflow: hidden;
      }

      .thq-mask-image-vertical {
        mask-image: linear-gradient(
          to bottom,
          transparent,
          black 1%,
          black 99%,
          transparent
        );
      }

      .thq-mask-image-horizontal {
        mask-image: linear-gradient(
          to right,
          transparent,
          black 1%,
          black 99%,
          transparent
        );
      }

      .thq-img-scale {
        transition: 0.3s;
      }

      .thq-img-scale:hover {
        scale: 1.05;
      }

      .thq-animated-card-bg-1 {
        width: 100%;
        height: 100%;
        transition: transform 0.3s;
        border-radius: var(--dl-layout-radius-cardradius);
        background-color: var(--dl-color-theme-accent1);
      }

      .thq-animated-card-bg-2 {
        transition: transform 0.3s;
        border-radius: var(--dl-layout-radius-cardradius);
        background-color: var(--dl-color-theme-accent2);
      }

      .thq-button-animated {
        outline: none;
        z-index: 1;
        overflow: hidden;
        position: relative;
        border-width: 2px;
      }

      .thq-input::placeholder {
        text-align: center;
        vertical-align: middle;
      }

      .thq-animated-group-container-vertical:hover div {
        animation-play-state: paused;
      }

      .thq-animated-group-container-horizontal:hover div {
        animation-play-state: paused;
      }

      .thq-animated-card-bg-2:has([data-animated="true"]:hover) {
        transform: translate3d(0px, 0px, 0px) scale3d(1, 1, 1) rotateX(0deg)
          rotateY(0deg) rotateZ(3deg) skew(0deg, 0deg);
      }

      .thq-animated-card-bg-1:has([data-animated="true"]:hover) {
        transform: translate3d(0px, 0px, 0px) scale3d(1, 1, 1) rotateX(0deg)
          rotateY(0deg) rotateZ(-6deg) skew(0deg, 0deg);
      }

      .thq-button-animated:before {
        top: 0;
        left: -20%;
        color: var(--dl-color-theme-neutral-light);
        width: 200%;
        height: 101%;
        content: "";
        z-index: 1;
        position: absolute;
        transform: scaleX(0);
        transition: transform 0.5s;
        border-radius: var(--dl-layout-radius-buttonradius);
        background-color: var(--dl-color-theme-neutral-dark);
        transform-origin: 0 0;
        transition-timing-function: cubic-bezier(0.5, 1.6, 0.4, 0.7);
      }

      .thq-button-animated:hover::before {
        color: var(--dl-color-theme-neutral-light);
        z-index: -1;
        transform: scaleX(1);
      }

      .btn {
        gap: var(--spacing-xs);
        border: 1px solid transparent;
        cursor: pointer;
        display: inline-flex;
        padding: var(--spacing-md) var(--spacing-lg);
        font-size: var(--font-size-base);
        box-shadow: var(--shadow-level-1);
        text-align: center;
        transition: all 0.2s ease-in-out;
        align-items: center;
        font-family: var(--font-family-body);
        font-weight: var(--font-weight-medium);
        line-height: var(--line-height-body);
        user-select: none;
        white-space: nowrap;
        border-radius: var(--border-radius-control);
        justify-content: center;
        text-decoration: none;
      }

      .btn-primary {
        color: var(--color-on-primary);
        border-color: var(--color-primary);
        background-color: var(--color-primary);
      }

      .btn-secondary {
        color: var(--color-on-secondary);
        border-color: var(--color-secondary);
        background-color: var(--color-secondary);
      }

      .btn-accent {
        color: var(--color-on-accent);
        border-color: var(--color-accent);
        background-color: var(--color-accent);
      }

      .btn-outline {
        color: var(--color-primary);
        border: 1px solid var(--color-primary);
        background-color: var(--color-surface);
      }

      .btn-link {
        color: var(--color-primary);
        box-shadow: none;
        border-color: transparent;
        text-decoration: underline;
        background-color: transparent;
      }

      .btn-sm {
        padding: var(--spacing-sm) var(--spacing-md);
      }

      .btn-lg {
        padding: var(--spacing-lg) var(--spacing-xl);
      }

      .btn-xl {
        padding: var(--spacing-xl) var(--spacing-2xl);
      }

      .section-title {
        font-size: var(--font-size-3xl);
        font-style: var(--font-style-heading);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        line-height: var(--line-height-heading);
        letter-spacing: var(--letter-spacing-heading);
        text-transform: var(--text-transform-heading);
      }

      .section-subtitle {
        opacity: 0.85;
        font-size: var(--font-size-lg);
        font-style: var(--font-style-subheading);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        line-height: var(--line-height-heading);
      }

      .section-content {
        font-size: var(--font-size-base);
        font-family: var(--font-family-body);
        font-weight: var(--font-weight-body);
        line-height: var(--line-height-body);
        letter-spacing: var(--letter-spacing-body);
      }

      .hero-title {
        font-size: var(--font-size-4xl);
        font-style: var(--font-style-heading);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        line-height: var(--line-height-heading);
        letter-spacing: var(--letter-spacing-heading);
        text-transform: var(--text-transform-heading);
      }

      .hero-subtitle {
        opacity: 0.85;
        font-size: var(--font-size-lg);
        font-style: var(--font-style-subheading);
        font-family: var(--font-family-body);
        font-weight: var(--font-weight-body);
        line-height: var(--line-height-body);
      }

      .btn:focus-visible {
        outline: 2px solid var(--color-outline);
        outline-offset: 2px;
      }

      .btn:disabled {
        cursor: not-allowed;
        opacity: 0.6;
        pointer-events: none;
      }

      .btn-primary:hover:not(:disabled) {
        border-color: color-mix(
          in oklab,
          var(--color-primary) 90%,
          var(--color-surface)
        );
        background-color: color-mix(
          in oklab,
          var(--color-primary) 90%,
          var(--color-surface)
        );
      }

      .btn-secondary:hover:not(:disabled) {
        border-color: color-mix(
          in oklab,
          var(--color-secondary) 90%,
          var(--color-surface)
        );
        background-color: color-mix(
          in oklab,
          var(--color-secondary) 90%,
          var(--color-surface)
        );
      }

      .btn-accent:hover:not(:disabled) {
        border-color: color-mix(
          in oklab,
          var(--color-accent) 90%,
          var(--color-surface)
        );
        background-color: color-mix(
          in oklab,
          var(--color-accent) 90%,
          var(--color-surface)
        );
      }

      .btn-outline:hover:not(:disabled) {
        color: var(--color-on-primary);
        border-color: var(--color-primary);
        background-color: var(--color-primary);
      }

      .btn-link:hover:not(:disabled) {
        color: color-mix(in oklab, var(--color-primary) 80%, black);
        text-decoration: underline;
      }

      .navigation-container {
        top: 0;
        left: 0;
        width: 100%;
        z-index: 1000;
        position: sticky;
        background: var(--color-surface);
        transition: background 0.3s ease;
        border-bottom: 1px solid var(--color-border);
      }

      .navigation-wrapper {
        margin: 0 auto;
        display: flex;
        padding: var(--spacing-md) var(--spacing-xl);
        max-width: var(--content-max-width);
        min-height: 4.5rem;
        align-items: center;
        justify-content: space-between;
      }

      .navigation-brand {
        gap: var(--spacing-sm);
        color: var(--color-on-surface);
        display: flex;
        transition: opacity 0.2s ease;
        align-items: center;
        text-decoration: none;
      }

      .navigation-links-desktop {
        gap: var(--spacing-2xl);
        display: flex;
        align-items: center;
      }

      .navigation-toggle {
        color: var(--color-on-surface);
        border: 1px solid var(--color-border);
        cursor: pointer;
        display: none;
        padding: var(--spacing-sm);
        background: transparent;
        transition: all 0.2s ease;
        border-radius: var(--border-radius-sm);
      }

      .navigation-logo-icon {
        color: var(--color-primary);
        width: 2.5rem;
        height: 2.5rem;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 15%, transparent);
        align-items: center;
        border-radius: var(--border-radius-md);
        justify-content: center;
      }

      .navigation-link {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-sm);
        transition: color 0.2s ease;
        font-family: var(--font-family-body);
        font-weight: var(--font-weight-medium);
        white-space: nowrap;
        text-decoration: none;
      }

      .navigation-mobile-overlay {
        inset: 0;
        display: none;
        z-index: 1100;
        position: fixed;
        transform: translateX(100%);
        background: var(--color-surface);
        min-height: 100vh;
        overflow-y: auto;
        transition: transform 0.4s cubic-bezier(0.16, 1, 0.3, 1);
        flex-direction: column;
      }

      .navigation-mobile-header {
        top: 0;
        display: flex;
        padding: var(--spacing-md) var(--spacing-xl);
        z-index: 1110;
        position: sticky;
        background: var(--color-surface);
        align-items: center;
        border-bottom: 1px solid var(--color-border);
        justify-content: space-between;
      }

      .navigation-mobile-content {
        gap: var(--spacing-4xl);
        flex: 1;
        display: flex;
        padding: var(--spacing-3xl) var(--spacing-xl);
        flex-direction: column;
      }

      .navigation-close {
        color: var(--color-on-surface);
        border: none;
        cursor: pointer;
        padding: var(--spacing-sm);
        background: transparent;
      }

      .navigation-mobile-links {
        gap: var(--spacing-xl);
        display: flex;
        flex-direction: column;
      }

      .navigation-mobile-footer {
        gap: var(--spacing-lg);
        display: flex;
        margin-top: auto;
        flex-direction: column;
        padding-bottom: var(--spacing-2xl);
      }

      .navigation-mobile-link {
        color: var(--color-on-surface);
        font-size: var(--font-size-3xl);
        transition:
          transform 0.2s ease,
          color 0.2s ease;
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        text-decoration: none;
      }

      .navigation-brand:hover {
        opacity: 0.8;
      }

      .navigation-brand .section-title {
        margin: 0;
        font-size: var(--font-size-xl);
      }

      .navigation-link:hover {
        color: var(--color-primary);
      }

      .navigation-toggle:hover {
        background: var(--color-surface-elevated);
        border-color: var(--color-primary);
      }

      .navigation-mobile-overlay.is-open {
        display: flex;
        transform: translateX(0);
      }

      .navigation-mobile-link:hover {
        color: var(--color-primary);
        transform: translateX(10px);
      }

      .navigation-mobile-footer .section-content {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-xs);
      }

      .footer-root {
        color: var(--color-on-surface);
        padding: var(--spacing-4xl) 0 var(--spacing-xl);
        overflow: hidden;
        position: relative;
        border-top: 1px solid var(--color-border);
        background-color: var(--color-surface);
      }

      .footer-glass-overlay {
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        z-index: 1;
        position: absolute;
        background:
          radial-gradient(
            circle at 10% 10%,
            color-mix(in srgb, var(--color-primary) 5%, transparent),
            transparent 40%
          ),
          radial-gradient(
            circle at 90% 90%,
            color-mix(in srgb, var(--color-secondary) 5%, transparent),
            transparent 40%
          );
        pointer-events: none;
      }

      .footer-container {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        z-index: 2;
        position: relative;
        max-width: var(--content-max-width);
      }

      .footer-grid {
        gap: var(--spacing-4xl);
        display: grid;
        margin-bottom: var(--spacing-4xl);
        grid-template-columns: 1.5fr 1fr 1fr;
      }

      .footer-bottom {
        padding-top: var(--spacing-2xl);
      }

      .footer-brand-col {
        gap: var(--spacing-xl);
        display: flex;
        flex-direction: column;
      }

      .footer-divider {
        width: 100%;
        height: 1px;
        background: linear-gradient(
          to right,
          transparent,
          var(--color-border),
          transparent
        );
        margin-bottom: var(--spacing-2xl);
      }

      .footer-legal-wrap {
        gap: var(--spacing-lg);
        display: flex;
        flex-wrap: wrap;
        align-items: center;
        justify-content: space-between;
      }

      .footer-logo-wrap {
        gap: var(--spacing-md);
        display: flex;
        align-items: center;
      }

      .footer-description {
        color: var(--color-on-surface-secondary);
        max-width: 400px;
      }

      .footer-social-links {
        gap: var(--spacing-md);
        display: flex;
      }

      .footer-col-title {
        color: var(--color-on-surface);
        display: inline-block;
        position: relative;
        margin-bottom: var(--spacing-xl);
      }

      .footer-nav-list {
        gap: var(--spacing-lg);
        margin: 0;
        display: flex;
        padding: 0;
        list-style: none;
        flex-direction: column;
      }

      .footer-nav-links {
        gap: var(--spacing-md);
        display: flex;
        flex-direction: column;
      }

      .footer-copyright {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-sm);
      }

      .footer-status-indicator {
        gap: var(--spacing-sm);
        border: 1px solid var(--color-border);
        display: flex;
        padding: var(--spacing-xs) var(--spacing-md);
        background: var(--color-surface-elevated);
        align-items: center;
        border-radius: var(--border-radius-full);
      }

      .footer-logo-icon {
        color: var(--color-on-primary);
        width: 40px;
        height: 40px;
        display: flex;
        background: var(--color-primary);
        box-shadow: 0 4px 12px
          color-mix(in srgb, var(--color-primary) 30%, transparent);
        align-items: center;
        border-radius: var(--border-radius-md);
        justify-content: center;
      }

      .footer-brand-name {
        color: var(--color-on-surface);
        font-size: var(--font-size-xl);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
        letter-spacing: var(--letter-spacing-heading);
      }

      .footer-social-icon {
        color: var(--color-on-surface);
        width: 44px;
        border: 1px solid var(--color-border);
        height: 44px;
        display: flex;
        background: var(--color-surface-elevated);
        transition: all 0.3s ease;
        align-items: center;
        border-radius: var(--border-radius-full);
        justify-content: center;
        text-decoration: none;
      }

      .footer-nav-item {
        gap: var(--spacing-md);
        color: var(--color-on-surface-secondary);
        display: flex;
        align-items: center;
      }

      .footer-link {
        color: var(--color-on-surface-secondary);
        width: fit-content;
        display: inline-block;
        transition:
          color 0.2s ease,
          transform 0.2s ease;
        text-decoration: none;
      }

      .footer-status-dot {
        width: 8px;
        height: 8px;
        animation: pulse-status 2s infinite;
        box-shadow: 0 0 8px #2ecc71;
        border-radius: 50%;
        background-color: #2ecc71;
      }

      .footer-status-text {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-xs);
        font-weight: var(--font-weight-medium);
      }

      .footer-nav-icon {
        color: var(--color-secondary);
        width: 20px;
        height: 20px;
        display: flex;
        align-items: center;
        justify-content: center;
      }

      .footer-social-icon:hover {
        color: var(--color-on-primary);
        transform: translateY(-3px);
        background: var(--color-primary);
        border-color: var(--color-primary);
      }

      .footer-col-title::after {
        left: 0;
        width: 24px;
        bottom: -4px;
        height: 2px;
        content: "";
        position: absolute;
        background: var(--color-accent);
      }

      .footer-link:hover {
        color: var(--color-accent);
        transform: translateX(4px);
      }

      .aqua-dashboard {
        color: var(--color-on-surface);
        font-family: var(--font-family-body);
        line-height: var(--line-height-body);
        background-color: var(--color-surface);
      }

      .live-snapshot {
        padding: var(--spacing-4xl) 0;
        overflow: hidden;
        position: relative;
        background: linear-gradient(
          135deg,
          color-mix(in srgb, var(--color-primary) 15%, transparent),
          var(--color-surface)
        );
      }

      .quick-stats {
        padding: var(--spacing-4xl) 0;
        background: var(--color-surface);
      }

      .recent-trends {
        padding: var(--spacing-4xl) 0;
        background: color-mix(
          in srgb,
          var(--color-secondary) 5%,
          var(--color-surface)
        );
      }

      .alerts-summary {
        padding: var(--spacing-2xl) var(--spacing-xl);
      }

      .device-health {
        padding: var(--spacing-4xl) 0;
      }

      .recent-events {
        padding: var(--spacing-4xl) 0;
        background: var(--color-surface-elevated);
      }

      .quick-actions {
        padding: var(--spacing-4xl) 0;
      }

      .live-snapshot-container {
        gap: var(--spacing-4xl);
        margin: 0 auto;
        display: flex;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
        align-items: center;
      }

      .quick-stats-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .recent-trends-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .alert-banner {
        gap: var(--spacing-xl);
        display: flex;
        padding: var(--spacing-xl);
        background: color-mix(
          in srgb,
          #e74c3c 15%,
          var(--color-surface-elevated)
        );
        align-items: center;
        border-left: 4px solid #e74c3c;
        border-radius: var(--border-radius-md);
        justify-content: space-between;
      }

      .device-health-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .recent-events-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .quick-actions-wrapper {
        margin: 0 auto;
        padding: 0 var(--spacing-xl);
        max-width: var(--content-max-width);
      }

      .live-snapshot-content {
        flex: 1;
      }

      .live-snapshot-readout {
        gap: var(--spacing-lg);
        flex: 1;
        display: flex;
        flex-direction: column;
      }

      .quick-stats-grid {
        gap: var(--spacing-xl);
        display: grid;
        margin-top: var(--spacing-2xl);
        grid-template-columns: repeat(2, 1fr);
      }

      .trends-grid {
        gap: var(--spacing-xl);
        display: grid;
        margin-top: var(--spacing-2xl);
        grid-template-columns: repeat(2, 1fr);
      }

      .alert-info {
        gap: var(--spacing-lg);
        display: flex;
        align-items: center;
      }

      .table-container {
        border: 1px solid var(--color-border);
        margin-top: var(--spacing-2xl);
        overflow-x: auto;
        border-radius: var(--border-radius-md);
      }

      .timeline-container {
        position: relative;
        margin-top: var(--spacing-2xl);
        padding-left: var(--spacing-xl);
      }

      .actions-grid {
        gap: var(--spacing-xl);
        display: grid;
        margin-top: var(--spacing-2xl);
        grid-template-columns: repeat(2, 1fr);
      }

      .live-snapshot-meta {
        gap: var(--spacing-xs);
        color: var(--color-on-surface-secondary);
        display: flex;
        font-size: var(--font-size-sm);
        margin-top: var(--spacing-lg);
        flex-direction: column;
      }

      .readout-card {
        gap: var(--spacing-xl);
        border: 1px solid var(--color-border);
        display: flex;
        padding: var(--spacing-xl);
        background: var(--color-surface-elevated);
        transition: transform 0.3s ease;
        align-items: center;
        border-radius: var(--border-radius-lg);
      }

      .stat-card {
        gap: var(--spacing-sm);
        border: 1px solid var(--color-border);
        display: flex;
        padding: var(--spacing-xl);
        background: var(--color-surface-elevated);
        border-radius: var(--border-radius-md);
        flex-direction: column;
      }

      .trend-module {
        border: 1px solid var(--color-border);
        padding: var(--spacing-xl);
        background: var(--color-surface);
        border-radius: var(--border-radius-md);
      }

      .alert-icon-box {
        color: #e74c3c;
        flex-shrink: 0;
      }

      .health-table {
        width: 100%;
        text-align: left;
        border-collapse: collapse;
      }

      .timeline-item {
        position: relative;
        padding-bottom: var(--spacing-2xl);
      }

      .action-btn {
        gap: var(--spacing-md);
        border: 1px solid var(--color-border);
        cursor: pointer;
        display: flex;
        padding: var(--spacing-2xl);
        background: var(--color-surface-elevated);
        transition: all 0.3s ease;
        align-items: center;
        border-radius: var(--border-radius-lg);
        flex-direction: column;
        justify-content: center;
      }

      .readout-icon-wrapper {
        color: var(--color-primary);
        width: 64px;
        height: 64px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 20%, transparent);
        align-items: center;
        border-radius: var(--border-radius-md);
        justify-content: center;
      }

      .readout-data {
        display: flex;
        flex-direction: column;
      }

      .stat-header {
        color: var(--color-on-surface-secondary);
        display: flex;
        align-items: center;
        justify-content: space-between;
      }

      .stat-value {
        color: var(--color-primary);
        font-size: var(--font-size-2xl);
        font-weight: var(--font-weight-heading);
      }

      .stat-trend {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-xs);
      }

      .trend-up {
        color: #2ecc71;
      }

      .trend-visual {
        height: 120px;
        margin: var(--spacing-md) 0;
        overflow: hidden;
        position: relative;
        background: color-mix(in srgb, var(--color-neutral) 30%, transparent);
        border-radius: var(--border-radius-sm);
      }

      .timeline-marker {
        top: 0;
        left: -25px;
        width: 12px;
        border: 2px solid var(--color-surface);
        height: 12px;
        position: absolute;
        background: var(--color-primary);
        border-radius: 50%;
      }

      .action-icon {
        width: 48px;
        height: 48px;
        display: flex;
        background: color-mix(in srgb, var(--color-primary) 10%, transparent);
        align-items: center;
        border-radius: 50%;
        justify-content: center;
      }

      .action-label {
        font-weight: var(--font-weight-medium);
      }

      .readout-label {
        color: var(--color-on-surface-secondary);
        font-size: var(--font-size-sm);
      }

      .readout-value {
        font-size: var(--font-size-3xl);
        font-family: var(--font-family-heading);
        font-weight: var(--font-weight-heading);
      }

      .sparkline {
        left: 0;
        width: 100%;
        bottom: 0;
        height: 100%;
        position: absolute;
        background: linear-gradient(
          0deg,
          color-mix(in srgb, var(--color-primary) 20%, transparent),
          transparent
        );
        mask-image: linear-gradient(
          90deg,
          transparent,
          black 20%,
          black 80%,
          transparent
        );
      }

      .spark-water {
        border-bottom: 2px solid var(--color-primary);
      }

      .spark-rssi {
        border-bottom: 2px solid var(--color-secondary);
      }

      .spark-temp {
        border-bottom: 2px solid var(--color-accent);
      }

      .spark-packet {
        border-bottom: 2px solid #2ecc71;
      }

      .event-time {
        color: var(--color-primary);
        font-size: var(--font-size-xs);
        font-weight: var(--font-weight-medium);
      }

      .event-title {
        margin: var(--spacing-xs) 0;
        font-size: var(--font-size-lg);
        font-weight: var(--font-weight-heading);
      }

      .status-badge {
        padding: var(--spacing-xs) var(--spacing-sm);
        font-size: var(--font-size-xs);
        font-weight: var(--font-weight-medium);
        border-radius: var(--border-radius-full);
      }

      .online {
        color: #2ecc71;
        background: color-mix(in srgb, #2ecc71 20%, transparent);
      }

      .warning {
        color: #f39c12;
        background: color-mix(in srgb, #f39c12 20%, transparent);
      }

      .offline {
        color: #e74c3c;
        background: color-mix(in srgb, #e74c3c 20%, transparent);
      }

      .readout-card:hover {
        transform: translateX(10px);
        border-color: var(--color-primary);
      }

      .readout-value small {
        opacity: 0.7;
        font-size: var(--font-size-lg);
        margin-left: var(--spacing-xs);
      }

      .health-table th {
        padding: var(--spacing-lg);
        background: var(--color-surface-elevated);
        font-weight: var(--font-weight-medium);
        border-bottom: 2px solid var(--color-border);
      }

      .health-table td {
        padding: var(--spacing-lg);
        border-bottom: 1px solid var(--color-border);
      }

      .timeline-container::before {
        top: 0;
        left: 0;
        width: 2px;
        bottom: 0;
        content: "";
        position: absolute;
        background: var(--color-border);
      }

      .action-btn:hover {
        color: var(--color-on-primary);
        transform: translateY(-5px);
        background: var(--color-primary);
        border-color: var(--color-primary);
      }

      .action-btn:hover .action-icon {
        color: var(--color-primary);
        background: var(--color-on-primary);
      }

      .Content {
        font-size: 16px;
        font-family: Inter;
        font-weight: 400;
        line-height: 1.15;
        text-transform: none;
        text-decoration: none;
      }

      .BodyFont {
        font-size: 1rem;
        font-family: Nunito Sans;
        font-weight: 400;
        line-height: 1.6;
        letter-spacing: 0.01em;
      }

      .Headings {
        font-size: 2em;
        font-family: Rubik;
        font-weight: 700;
        line-height: 1.2;
        letter-spacing: 0.02em;
      }

      @media (max-width: 991px) {
        .thq-grid-4 {
          grid-template-columns: 1fr 1fr 1fr;
        }
        .navigation-links-desktop {
          gap: var(--spacing-lg);
        }
        .footer-grid {
          gap: var(--spacing-3xl);
          grid-template-columns: 1fr 1fr;
        }
        .footer-brand-col {
          text-align: center;
          align-items: center;
          grid-column: span 2;
        }
        .footer-description {
          max-width: 600px;
        }
        .live-snapshot-container {
          text-align: center;
          flex-direction: column;
        }
      }

      @media (max-width: 767px) {
        .thq-section-padding {
          padding: var(--dl-layout-space-threeunits);
        }
        .thq-flex-column {
          gap: var(--dl-layout-space-oneandhalfunits);
        }
        .thq-flex-row {
          gap: var(--dl-layout-space-oneandhalfunits);
        }
        .thq-grid-6 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          grid-template-columns: 1fr 1fr 1fr;
        }
        .thq-grid-5 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          grid-template-columns: 1fr 1fr 1fr;
        }
        .thq-card {
          padding: var(--dl-layout-space-oneandhalfunits);
        }
        .thq-grid-3 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          grid-template-columns: 1fr 1fr;
        }
        .thq-grid-4 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          flex-direction: row;
          grid-template-columns: 1fr 1fr;
        }
        .thq-grid-2 {
          grid-gap: var(--dl-layout-space-oneandhalfunits);
          grid-template-columns: 1fr;
        }
        .thq-img-scale {
          width: 100%;
        }
        .navigation-links-desktop {
          display: none;
        }
        .navigation-toggle {
          display: flex;
        }
        .footer-root {
          padding: var(--spacing-3xl) 0 var(--spacing-xl);
        }
        .footer-grid {
          gap: var(--spacing-2xl);
          grid-template-columns: 1fr;
        }
        .footer-brand-col {
          grid-column: span 1;
        }
        .footer-legal-wrap {
          text-align: center;
          flex-direction: column;
        }
        .alert-banner {
          text-align: center;
          flex-direction: column;
        }
        .quick-stats-grid {
          grid-template-columns: 1fr;
        }
        .trends-grid {
          grid-template-columns: 1fr;
        }
        .actions-grid {
          grid-template-columns: 1fr;
        }
        .readout-card {
          text-align: center;
          flex-direction: column;
        }
      }

      @media (max-width: 479px) {
        .thq-section-padding {
          padding: var(--dl-layout-space-oneandhalfunits);
        }
        .thq-flex-column {
          gap: var(--dl-layout-space-unit);
        }
        .thq-flex-row {
          gap: var(--dl-layout-space-unit);
        }
        .thq-grid-6 {
          grid-gap: var(--dl-layout-space-unit);
          grid-template-columns: 1fr 1fr;
        }
        .thq-grid-5 {
          grid-gap: var(--dl-layout-space-unit);
          grid-template-columns: 1fr 1fr;
        }
        .thq-grid-3 {
          grid-gap: var(--dl-layout-space-unit);
          align-items: center;
          grid-template-columns: 1fr;
        }
        .thq-grid-4 {
          grid-gap: var(--dl-layout-space-unit);
          align-items: center;
          flex-direction: column;
          grid-template-columns: 1fr;
        }
        .thq-grid-2 {
          grid-gap: var(--dl-layout-space-unit);
        }
        .thq-grid-auto-300 {
          grid-template-columns: 1fr;
        }
        .footer-container {
          padding: 0 var(--spacing-lg);
        }
        .footer-logo-wrap {
          flex-direction: column;
        }
        .home-hero-title {
          font-size: var(--font-size-3xl);
        }
        .readout-value {
          font-size: var(--font-size-2xl);
        }
      }

      /* footer.css */
      .footer-container1 {
        display: contents;
      }

      .footer-container2 {
        display: none;
      }

      .footer-container3 {
        display: contents;
      }

      .footer-container4 {
        display: none;
      }

      .footer-container5 {
        display: contents;
      }

      /* navigation.css */
      .navigation-container1 {
        display: contents;
      }

      .navigation-container2 {
        display: none;
      }

      .navigation-container3 {
        display: contents;
      }

      .navigation-container4 {
        display: none;
      }

      .navigation-container5 {
        display: contents;
      }

      .settings-header {
        margin-bottom: var(--spacing-2xl);
      }

      .settings-form {
        gap: var(--spacing-xl);
        display: flex;
        flex-direction: column;
      }

      .form-group label {
        color: var(--color-on-surface-secondary);
        font-weight: var(--font-weight-medium);
      }

      .form-group {
        gap: var(--spacing-sm);
        display: flex;
        flex-direction: column;
      }

      .input-wrapper {
        display: flex;
        position: relative;
        align-items: center;
      }

      .input-icon {
        color: var(--color-on-surface-secondary);
        right: var(--spacing-lg);
        position: absolute;
        pointer-events: none;
      }

      .form-actions {
        gap: var(--spacing-md);
        display: flex;
        margin-top: var(--spacing-lg);
        flex-direction: column;
      }

      .form-input:focus {
        outline: none;
        box-shadow: 0 0 0 3px
          color-mix(in srgb, var(--color-primary) 20%, transparent);
        border-color: var(--color-primary);
      }

      .parameters-settings-container1 {
        width: 100%;
        display: block;
        /* min-height: 100vh; */
      }

      .form-input {
        color: var(--color-on-surface);
        width: 100%;
        border: 1px solid var(--color-border);
        padding: var(--spacing-md) var(--spacing-lg);
        font-size: var(--font-size-base);
        transition:
          border-color 0.2s,
          box-shadow 0.2s;
        font-family: var(--font-family-body);
        border-radius: var(--border-radius-control);
        background-color: var(--color-surface);
      }

      .input-suffix {
        color: var(--color-on-surface-secondary);
        right: var(--spacing-lg);
        position: absolute;
        font-size: var(--font-size-sm);
        pointer-events: none;
      }

      .aquasignal-dashboard {
        gap: var(--spacing-3xl);
        color: var(--color-on-surface);
        margin: 0 auto;
        display: flex;
        padding: var(--spacing-xl) var(--spacing-lg);
        max-width: 700px;
        min-height: 70vh;
        flex-direction: column;
        background-color: var(--color-surface);
      }
    </style>
  </head>
  <body>
    <div>
      <div class="home-container1">
        <navigation-wrapper class="navigation-wrapper">
          <!--Navigation component-->
          <div class="navigation-container1">
            <nav class="navigation-container">
              <div class="navigation-wrapper">
                <a href="index.html">
                  <div aria-label="AquaSignal Home" class="navigation-brand">
                    <div class="navigation-logo-icon">
                      <svg
                        xmlns="http://www.w3.org/2000/svg"
                        width="24"
                        height="24"
                        viewBox="0 0 24 24"
                      >
                        <g
                          fill="none"
                          stroke="currentColor"
                          stroke-linecap="round"
                          stroke-linejoin="round"
                          stroke-width="2"
                        >
                          <path
                            d="M5.116 4.104A1 1 0 0 1 6.11 3h11.78a1 1 0 0 1 .994 1.105L17.19 20.21A2 2 0 0 1 15.2 22H8.8a2 2 0 0 1-2-1.79z"
                          ></path>
                          <path d="M6 12a5 5 0 0 1 6 0a5 5 0 0 0 6 0"></path>
                        </g>
                      </svg>
                    </div>
                    <span class="section-title">Water Level</span>
                  </div>
                </a>
                <div class="navigation-links-desktop">
                  <a href="/">
                    <div class="navigation-link"><span>Home</span></div>
                  </a>
                </div>
                <button
                  id="navToggle"
                  aria-label="Toggle Menu"
                  aria-expanded="false"
                  class="navigation-toggle"
                >
                  <svg
                    xmlns="http://www.w3.org/2000/svg"
                    width="24"
                    height="24"
                    viewBox="0 0 24 24"
                    class="icon-menu"
                  >
                    <path
                      fill="none"
                      stroke="currentColor"
                      stroke-linecap="round"
                      stroke-linejoin="round"
                      stroke-width="2"
                      d="M4 6h16M4 12h16M4 18h16"
                    ></path>
                  </svg>
                </button>
              </div>
            </nav>
            <div id="mobileMenu" class="navigation-mobile-overlay">
              <div class="navigation-mobile-header">
                <a href="index.html">
                  <div aria-label="AquaSignal Home" class="navigation-brand">
                    <div class="navigation-logo-icon">
                      <svg
                        xmlns="http://www.w3.org/2000/svg"
                        width="24"
                        height="24"
                        viewBox="0 0 24 24"
                      >
                        <g
                          fill="none"
                          stroke="currentColor"
                          stroke-linecap="round"
                          stroke-linejoin="round"
                          stroke-width="2"
                        >
                          <path
                            d="M5.116 4.104A1 1 0 0 1 6.11 3h11.78a1 1 0 0 1 .994 1.105L17.19 20.21A2 2 0 0 1 15.2 22H8.8a2 2 0 0 1-2-1.79z"
                          ></path>
                          <path d="M6 12a5 5 0 0 1 6 0a5 5 0 0 0 6 0"></path>
                        </g>
                      </svg>
                    </div>
                    <span class="section-title">Water Level</span>
                  </div>
                </a>
                <button
                  id="navClose"
                  aria-label="Close Menu"
                  class="navigation-close"
                >
                  <svg
                    xmlns="http://www.w3.org/2000/svg"
                    width="24"
                    height="24"
                    viewBox="0 0 24 24"
                  >
                    <path
                      fill="none"
                      stroke="currentColor"
                      stroke-linecap="round"
                      stroke-linejoin="round"
                      stroke-width="2"
                      d="M18 6L6 18M6 6l12 12"
                    ></path>
                  </svg>
                </button>
              </div>
              <div class="navigation-mobile-content">
                <div class="navigation-mobile-links">
                  <a href="/">
                    <div class="navigation-mobile-link">
                      <span>Home</span>
                    </div>
                  </a>
                </div>
                <div class="navigation-mobile-footer">
                  <p class="section-content">Real-time water level</p>
                </div>
              </div>
            </div>
            <div class="navigation-container2">
              <div class="navigation-container3">
                <style>
                  @media (prefers-reduced-motion: reduce) {
                    .navigation-mobile-overlay {
                      transition: opacity 0.3s ease;
                      transform: none;
                      opacity: 0;
                    }
                    .navigation-mobile-overlay.is-open {
                      opacity: 1;
                    }
                    .aquasignal-dashboard {
                      max-width: 500px;
                    }
                  }
                </style>
              </div>
            </div>
            <div class="navigation-container4">
              <div class="navigation-container5">
                <script defer="" data-name="navigation-logic">
                  document.addEventListener("DOMContentLoaded", function () {
                    (function () {
                      const navToggle = document.getElementById("navToggle");
                      const navClose = document.getElementById("navClose");
                      const mobileMenu = document.getElementById("mobileMenu");
                      const body = document.body;

                      function openMenu() {
                        mobileMenu.classList.add("is-open");
                        navToggle.setAttribute("aria-expanded", "true");
                        body.style.overflow = "hidden";
                      }

                      function closeMenu() {
                        mobileMenu.classList.remove("is-open");
                        navToggle.setAttribute("aria-expanded", "false");
                        body.style.overflow = "";
                      }

                      navToggle.addEventListener("click", openMenu);
                      navClose.addEventListener("click", closeMenu);

                      // Close menu when clicking on a link
                      const mobileLinks = document.querySelectorAll(
                        ".navigation-mobile-link",
                      );
                      mobileLinks.forEach((link) => {
                        link.addEventListener("click", closeMenu);
                      });

                      // Close menu on ESC key
                      document.addEventListener("keydown", (e) => {
                        if (
                          e.key === "Escape" &&
                          mobileMenu.classList.contains("is-open")
                        ) {
                          closeMenu();
                        }
                      });
                    })();
                  });
                </script>
              </div>
            </div>
          </div>
        </navigation-wrapper>

        <div class="parameters-settings-container1">
          <main class="aquasignal-dashboard">
            <section class="dashboard-settings">
              <div class="settings-container">
                <div class="settings-header">
                  <h2 class="section-title">Parameter Configuration</h2>
                  <span class="section-content"
                    >Webserver will automatically close in
                    <span id="countdownTimer">--:--</span></span
                  >
                </div>
                <form class="settings-form">
                  <div class="form-group">
                    <label for="interval-time" class="section-content">
                      Interval sending time in minute
                    </label>
                    <div class="input-wrapper">
                      <input
                        type="number"
                        id="report_min"
                        name="report_min"
                        required="true"
                        min="1"
                        max="1440"
                        placeholder="e.g. 15"
                        data-form-field-id="interval-time"
                        class="form-input"
                      />
                      <span class="input-suffix">min</span>
                    </div>
                  </div>
                  <div class="form-group">
                    <label for="web_on" class="section-content">
                      Web Server Timeout
                    </label>
                    <div class="input-wrapper">
                      <input
                        type="number"
                        id="web_on"
                        name="web_on"
                        required="true"
                        min="1"
                        max="1440"
                        placeholder="e.g. 15"
                        data-form-field-id="web_on"
                        class="form-input"
                      />
                      <span class="input-suffix">min</span>
                    </div>
                  </div>
                  <div class="form-group">
                    <label for="tenant_id" class="section-content">
                      Tenant & Device ID
                    </label>
                    <div class="input-wrapper">
                      <input
                        type="text"
                        id="tenant_id"
                        name="tenant_id"
                        required="true"
                        placeholder="e.g. 001"
                        data-form-field-id="tenant_id"
                        class="form-input"
                      />
                      <span class="input-suffix">Tenant</span>
                    </div>
                    <div class="input-wrapper">
                      <input
                        type="text"
                        id="device_id"
                        name="device_id"
                        required="true"
                        placeholder="e.g. D01"
                        data-form-field-id="device_id"
                        class="form-input"
                      />
                      <span class="input-suffix">Device</span>
                    </div>
                  </div>
                  <div class="form-group">
                    <label for="location" class="section-content">
                      Location
                    </label>
                    <div class="input-wrapper">
                      <input
                        type="text"
                        id="location"
                        name="location"
                        required="false"
                        maxlength="32"
                        placeholder="e.g. Site A"
                        data-form-field-id="location"
                        class="form-input"
                      />
                      <span class="input-suffix">Location</span>
                    </div>
                  </div>
                  <div class="form-group">
                    <label for="press_m" class="section-content">
                      Parameter calibration
                    </label>
                    <div class="input-wrapper">
                      <input
                        type="number"
                        step="0.01"
                        id="press_m"
                        name="press_m"
                        required="true"
                        placeholder="0.00"
                        data-form-field-id="press_m"
                        class="form-input"
                      />
                      <span class="input-suffix">( Slope M )</span>
                    </div>
                    <div class="input-wrapper">
                      <input
                        type="number"
                        step="0.01"
                        id="press_c"
                        name="press_c"
                        required="true"
                        placeholder="0.00"
                        data-form-field-id="press_c"
                        class="form-input"
                      />
                      <span class="input-suffix">( Offset C )</span>
                    </div>
                  </div>
                  <div class="form-actions">
                    <button
                      type="submit"
                      id="btnSave"
                      onclick="saveSettings()"
                      name="button"
                      data-form-field-id="btnSave"
                      class="parameters-settings-action-btn btn btn-primary btn-lg"
                    >
                      <svg
                        xmlns="http://www.w3.org/2000/svg"
                        width="20"
                        height="20"
                        viewBox="0 0 24 24"
                        fill="none"
                        stroke="currentColor"
                        stroke-linecap="round"
                        stroke-linejoin="round"
                        stroke-width="2"
                      >
                        <path
                          d="M15.2 3a2 2 0 0 1 1.4.6l3.8 3.8a2 2 0 0 1 .6 1.4V19a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2z"
                        ></path>
                        <path
                          d="M17 21v-7a1 1 0 0 0-1-1H8a1 1 0 0 0-1 1v7M7 3v4a1 1 0 0 0 1 1h7"
                        ></path>
                      </svg>
                      <span>Save Configuration</span>
                    </button>
                    <button
                      type="button"
                      onclick="loadSettings()"
                      id="btnLoad"
                      name="button"
                      data-form-field-id="btnLoad"
                      class="parameters-settings-action-btn btn btn-lg btn-outline"
                    >
                      <svg
                        xmlns="http://www.w3.org/2000/svg"
                        width="20"
                        height="20"
                        viewBox="0 0 24 24"
                        fill="none"
                        stroke="currentColor"
                        stroke-linecap="round"
                        stroke-linejoin="round"
                        stroke-width="2"
                      >
                        <path
                          d="M4 17v2a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2v-2M7 9l5-5l5 5m-5-5v12"
                        ></path>
                      </svg>
                      <span>Load Defaults</span>
                    </button>
                    <button
                      type="button"
                      onclick="closeWebServer()"
                      id="btnClose"
                      name="button"
                      data-form-field-id="btnClose"
                      class="parameters-settings-action-btn btn btn-lg btn-outline"
                    >
                      <svg
                        xmlns="http://www.w3.org/2000/svg"
                        width="20"
                        height="20"
                        viewBox="0 0 24 24"
                        fill="none"
                        stroke="currentColor"
                        stroke-linecap="round"
                        stroke-linejoin="round"
                        stroke-width="2"
                      >
                        <path d="M18 6L6 18M6 6l12 12"></path>
                      </svg>
                      <span>Close Web</span>
                    </button>
                  </div>
                </form>

                <div
                  id="status"
                  class="status"
                  style="
                    display: none;
                    margin-top: 20px;
                    margin-left: auto;
                    margin-right: auto;
                    text-align: center;
                    width: 100%;
                    justify-content: center;
                    align-items: center;
                  "
                ></div>
              </div>
            </section>
          </main>
        </div>

        <script>
          function setStatus(message, type = "") {
            const statusDiv = document.getElementById("status");
            if (!message) {
              statusDiv.style.display = "none";
              return;
            }

            statusDiv.style.display = "flex";
            statusDiv.textContent = message;
            statusDiv.className = "status";

            if (type === "error") {
              statusDiv.classList.add("error");
            } else if (type === "loading") {
              statusDiv.classList.add("loading");
              statusDiv.innerHTML =
                '<span class="spinner"></span><span>' + message + "</span>";
            } else {
              statusDiv.classList.add("success");
            }
          }

          function setButtonLoading(buttonId, isLoading) {
            const btn = document.getElementById(buttonId);
            if (isLoading) {
              btn.disabled = true;
              btn.innerHTML =
                '<span class="spinner"></span><span>Processing...</span>';
            } else {
              btn.disabled = false;
              if (buttonId === "btnLoad") {
                btn.innerHTML = "<span>📥</span><span>Load Values</span>";
              } else {
                btn.innerHTML = "<span>💾</span><span>Save Settings</span>";
              }
            }
          }

          function loadSettings() {
            setStatus("Loading current settings...", "loading");
            setButtonLoading("btnLoad", true);

            fetch("/api/settings")
              .then((response) => {
                if (!response.ok)
                  throw new Error(`HTTP error! status: ${response.status}`);
                return response.json();
              })
              .then((data) => {
                document.getElementById("press_m").value = data.press_m || "";
                document.getElementById("press_c").value = data.press_c || "";
                document.getElementById("report_min").value =
                  data.report_min || "";
                document.getElementById("web_on").value = data.web_on || "";
                document.getElementById("tenant_id").value =
                  data.tenant_id || "";
                document.getElementById("device_id").value =
                  data.device_id || "";
                document.getElementById("location").value =
                  data.location || "";

                setStatus("✅ Settings loaded successfully!", "success");
                setTimeout(() => setStatus(""), 3000);
              })
              .catch((error) => {
                setStatus(
                  "❌ Failed to load settings: " + error.message,
                  "error",
                );
                setTimeout(() => setStatus(""), 5000);
              })
              .finally(() => {
                setButtonLoading("btnLoad", false);
              });
          }

          function saveSettings() {
            setStatus("Saving settings...", "loading");
            setButtonLoading("btnSave", true);

            const data = {
              press_m:
                parseFloat(document.getElementById("press_m").value) || 1.0,
              press_c:
                parseFloat(document.getElementById("press_c").value) || 0.0,
              report_min:
                parseInt(document.getElementById("report_min").value) || 15,
              web_on: parseInt(document.getElementById("web_on").value) || 5,
              tenant_id: (document.getElementById("tenant_id").value || "").trim(),
              device_id: (document.getElementById("device_id").value || "").trim(),
              location: (document.getElementById("location").value || "").trim(),
            };

            if (data.location && data.location.length > 32) {
              setStatus("? Location terlalu panjang (maks 32 karakter)", "error");
              setButtonLoading("btnSave", false);
              return;
            }

            fetch("/api/settings", {
              method: "POST",
              headers: { "Content-Type": "application/json" },
              body: JSON.stringify(data),
            })
              .then((response) => {
                if (!response.ok)
                  throw new Error(`HTTP error! status: ${response.status}`);
                return response.json();
              })
              .then((data) => {
                setStatus(
                  "✅ " + (data.message || "Settings saved successfully!"),
                  "success",
                );
                setTimeout(() => setStatus(""), 3000);
              })
              .catch((error) => {
                setStatus("❌ Failed to save: " + error.message, "error");
                setTimeout(() => setStatus(""), 5000);
              })
              .finally(() => {
                setButtonLoading("btnSave", false);
              });
          }


          function closeWebServer() {
            if (!confirm("Close web server (AP) now?")) {
              return;
            }
            setStatus("Closing web server...", "loading");
            const btn = document.getElementById("btnClose");
            if (btn) btn.disabled = true;

            fetch("/api/webserver-close", { method: "POST" })
              .then((response) => {
                if (!response.ok)
                  throw new Error(`HTTP error! status: ${response.status}`);
                return response.json();
              })
              .then((data) => {
                setStatus("? " + (data.message || "Web server closed"), "success");
                setTimeout(() => setStatus(""), 3000);
              })
              .catch((error) => {
                setStatus("? Failed to close: " + error.message, "error");
                setTimeout(() => setStatus(""), 5000);
              })
              .finally(() => {
                if (btn) btn.disabled = false;
              });
          }

          function formatTime(seconds) {
            const mins = Math.floor(seconds / 60);
            const secs = seconds % 60;
            return (
              String(mins).padStart(2, "0") +
              ":" +
              String(secs).padStart(2, "0")
            );
          }

          function updateCountdown() {
            fetch("/api/webserver-timeout")
              .then((response) => {
                if (!response.ok) throw new Error("Failed to fetch timeout");
                return response.json();
              })
              .then((data) => {
                const remainingSeconds = data.remaining_seconds || 0;
                if (remainingSeconds > 0) {
                  document.getElementById("countdownTimer").textContent =
                    formatTime(remainingSeconds);
                } else {
                  document.getElementById("countdownTimer").textContent =
                    "00:00";
                }
              })
              .catch((error) => {
                console.error("Error updating countdown:", error);
                document.getElementById("countdownTimer").textContent = "--:--";
              });
          }

          // Auto-load settings when page loads
          window.onload = function () {
            loadSettings();
            updateCountdown(); // Initial update
            // Update countdown every second
            setInterval(updateCountdown, 1000);
          };
        </script>

        <footer-wrapper class="footer-wrapper">
          <!--Footer component-->
          <div class="footer-container1">
            <footer class="footer-root">
              <div class="footer-glass-overlay"></div>
              <div class="footer-container">
                <div class="footer-grid">
                  <div class="footer-column footer-brand-col">
                    <div class="footer-logo-wrap">
                      <div class="footer-logo-icon">
                        <svg
                          xmlns="http://www.w3.org/2000/svg"
                          width="24"
                          height="24"
                          viewBox="0 0 24 24"
                        >
                          <path
                            fill="none"
                            stroke="currentColor"
                            stroke-linecap="round"
                            stroke-linejoin="round"
                            stroke-width="2"
                            d="M12 22a7 7 0 0 0 7-7c0-2-1-3.9-3-5.5s-3.5-4-4-6.5c-.5 2.5-2 4.9-4 6.5S5 13 5 15a7 7 0 0 0 7 7"
                          ></path>
                        </svg>
                      </div>
                      <span class="footer-brand-name">Water Level</span>
                    </div>
                    <p class="footer-description section-content">
                      IO dashboard for real-time water level monitoring.
                    </p>
                  </div>
                  <div class="footer-column">
                    <h2 class="footer-col-title section-subtitle">
                      Core Metrics
                    </h2>
                    <ul class="footer-nav-list">
                      <li class="footer-nav-item">
                        <div class="footer-nav-icon">
                          <svg
                            xmlns="http://www.w3.org/2000/svg"
                            width="24"
                            height="24"
                            viewBox="0 0 24 24"
                          >
                            <path
                              fill="none"
                              stroke="currentColor"
                              stroke-linecap="round"
                              stroke-linejoin="round"
                              stroke-width="2"
                              d="M12 22a7 7 0 0 0 7-7c0-2-1-3.9-3-5.5s-3.5-4-4-6.5c-.5 2.5-2 4.9-4 6.5S5 13 5 15a7 7 0 0 0 7 7"
                            ></path>
                          </svg>
                        </div>
                        <span class="section-content">Water Level (m)</span>
                      </li>
                      <li class="footer-nav-item">
                        <div class="footer-nav-icon">
                          <svg
                            xmlns="http://www.w3.org/2000/svg"
                            width="24"
                            height="24"
                            viewBox="0 0 24 24"
                          >
                            <path
                              fill="none"
                              stroke="currentColor"
                              stroke-linecap="round"
                              stroke-linejoin="round"
                              stroke-width="2"
                              d="M2 20h.01M7 20v-4m5 4v-8m5 8V8m5-4v16"
                            ></path>
                          </svg>
                        </div>
                        <span class="section-content">
                          RSSI Signal Strength
                        </span>
                      </li>
                    </ul>
                  </div>
                </div>
                <div class="footer-bottom">
                  <div class="footer-divider"></div>
                  <div class="footer-legal-wrap">
                    <p class="footer-copyright section-content">
                      &amp;2026 Water Level Monitoring. All rights reserved.
                    </p>
                  </div>
                </div>
              </div>
            </footer>
          </div>
        </footer-wrapper>
      </div>
    </div>
  </body>
</html>
)rawliteral";
