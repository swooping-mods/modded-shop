# Modded Shop: behavior and implementation

Describes the retained payload **0.2.1**. The behavior prose describes the retained payload; current candidate source and metadata are identified below. Gameplay qualification is a separate requirement.


<!-- source-only-sync -->
## Current source candidate

Source version **0.2.1** is saved from workshop revision `ca32bbf79ce0840d5166a232bdb3a9fdcd761254`. The retained installable payload remains **0.2.1** with its original bytes. This source update does not rebuild or requalify that payload. The current source and metadata define the candidate; gameplay, rendered behavior and co-op remain unqualified for rebuilt bytes.

The authored behavior and lifecycle descriptions below are retained from the published payload. They are not new qualification evidence for the source candidate. The integration table below follows the current candidate metadata.

The exported test sources have deferred generated harness includes; their fixture closure is incomplete and they are not qualified executable tests. See `provenance.json` for the exact missing include identities.
<!-- /source-only-sync -->

## Behavior

An optional standalone entry for the shared Modded Shop. Ctrl+Shift+F2 opens Shop Framework’s separate native shop tab. Registered provider offers display their own real price, ownership, availability and Buy action while vanilla shops retain vanilla rows. The entry delegates to Shop Framework rather than maintaining a second shop implementation or shortcut owner.

## State and lifecycle

The entry itself stores no ownership or save data. Shop Framework owns native menu lifetime and provider routing; individual providers own payment and persistence. This DLL’s startup requires that shared framework to be ready.

## Integration and configuration

Runtime dependencies: [shop-framework](https://github.com/swooping-mods/shop-framework).

The [module metadata](../source/mods/modded-shop/mod.json) owns the version and declared integration contract. Native modules start at `MoonLab_ModStart`. Game/Unity integrations target the pinned Steam Windows x64 IL2CPP build.

| Service | ABI | Table size |
|---|---:|---|
| Requires `shop-framework.shop` | 1 | at least 56 bytes |

## Implementation sources

- [mod.c](../source/mods/modded-shop/mod.c)
- [feature.h](../source/mods/modded-shop/feature.h)

## Verification boundary

Installing this entry alone supplies no additional items. Purchase eligibility, guest support and saved ownership depend on each provider; a working shop shell does not qualify those transactions.

`python3 build.py --check` verifies the exported source hashes. It does not execute the mod or qualify the behaviors above. Installation and independent build prerequisites are in the [README](../README.md).
